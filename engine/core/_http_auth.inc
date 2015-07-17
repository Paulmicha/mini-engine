<?php

/**
 *  @file
 *  HTTP Basic authentication
 *  
 *  Source :
 *  http://evertpot.com/223/
 */


/**
 *  Basic Auth
 *  
 *  Handles response (HTTP headers + tpl) in case of failure,
 *  returns true otherwise.
 *  
 *  About "Basic" : username and password are sent over the wire using base64 encoding.
 *  Not really secure, unless you have SSL in place.
 *  
 *  @param Array $options
 *  @return Boolean
 *  
 *  @example
 *      $authorized = basic_auth( array( 'allowed' => array( 'foo' => 'bar' )));
 */
function basic_auth( $options = array())
{
    //      Overridable defaults
    $options += array(
        'realm' => "HTTP Authentication",
        'allowed' => array(),
    );
    extract( $options );
    
    //      Minimum requirement :
    //      must be called with non-empty list of valid credentials
    if ( empty( $allowed ))
    {
        //      In this case, issue a 404
        //      (beacuse something's wrong with the app, not the authentication)
        send_404();
        return false;
    }
    
    $username = null;
    $password = null;

    //      Check if credentials are already sent :
    //      • with Apache mod_php
    if ( isset( $_SERVER[ 'PHP_AUTH_USER' ]))
    {
        $username = $_SERVER[ 'PHP_AUTH_USER' ];
        $password = $_SERVER[ 'PHP_AUTH_PW' ];
    }
    //      • with most other servers
    else if ( isset( $_SERVER[ 'HTTP_AUTHORIZATION' ]))
    {
        if ( strpos( strtolower( $_SERVER[ 'HTTP_AUTHORIZATION' ]), 'basic' ) === 0 ) {
            list( $username, $password ) = explode( ':', base64_decode( substr( $_SERVER[ 'HTTP_AUTHORIZATION' ], 6 )), 2 );
        }
    }
    
    //      Ask for credentials
    if ( is_null( $username )) {
        header( 'WWW-Authenticate: Basic realm="'. $realm .'"' );
    }
    
    //      Test credentials (may be empty)
    else
    {
        foreach( $allowed as $u => $p)
        {
            if ( $username == $u && $password == $p ) {
                return true;
            }
        }
    }
    
    //      Unauthorized (user hits cancel)
    send_401();
    return false;
}


