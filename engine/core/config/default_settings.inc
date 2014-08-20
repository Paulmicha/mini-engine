<?php

/**
 *  @file
 *  Mini Engine default settings
 *  (global scope "reserved" vars)
 */

$mini_engine_version = "1.0.1-alpha";


//      Routing globals
$base_path = base_path();
$request_arr = array();
$routing_max_depth = 9;//           max number of parts (default deepest URL ex: http://example.com/up/to/nine/elements/separated/by/slashes/by/default)
$routing_path = "routing";//        default dir to scan for routing handlers
$routing_filename = "index";


//      Template globals
$theme_path = "theme";//            dir to scan for template files & assets
$base_tpl = "page";
$container_tpl = "$theme_path/$base_tpl.tpl.php";
$content_tpl = "$theme_path/index.tpl.php";
$content_tpl_extensions_arr = array( '.tpl.php', '.html' );//       file extensions allowed for use as content tpl


//      Content globals
$page_title = "Welcome home";
$content = "";
$content_rendered = "";


//      Spaces :
//      Contains HTML markup for use in tpl files.
//      (bridges templates & content ~ expresses what goes where)
//      @example theme/page.tpl.php
$spaces = array();
$spaces[ 'head' ] = '';
$spaces[ 'page_top' ] = '';
$spaces[ 'page_bottom' ] = '';


//      Metadata global
$metadata = array();
$metadata[ 'site_name' ] = "Mini-engine";
//$metadata[ 'head_page_title' ] = $page_title .' — '. $metadata[ 'site_name' ];
$metadata[ 'description' ] = "Mini-engine";
$metadata[ 'lang' ] = 'en';
$metadata[ 'locale' ] = 'en_EN';
$metadata[ 'timezone' ] = 'UTC';//        ex: 'Europe/Paris', etc.


//      Misc. globals
$html_attr = array(
    'lang' => $metadata[ 'lang' ],
    'class' => 'no-js',
);
$body_attr = array();

$http_s = "http://";
if ( @$_SERVER[ 'HTTPS' ] == "on" ) {
    $http_s = "https://";
}


//      Debug
$debug = array(

    //      Display php errors
    'php' => 0,

    //      Routing
    'routing' => 0,
    'tpl' => 0,
    'req' => 0,

    //      Execution time (displayed at the bottom of every pages)
    'exec_time' => 0,
);
