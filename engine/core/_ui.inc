<?php

/**
 *  @file
 *  UI (theming helpers)
 */


/**
 *  Render html attributes
 */
function attributes( $attributes )
{
    $return = '';
    
    if ( !empty( $attributes ) && is_array( $attributes ))
    {
        foreach( $attributes as $attribute => $value )
        {
            if ( !empty( $value ) && !empty( $attribute ) && !is_numeric( $attribute ))
            {
                $value = addcslashes( $value, "'" );
                $return .= " $attribute='$value'";
            }
        }
    }
    
    return $return;
}



/**
 *  Render tpl
 *  Warning : NOT checking if tpl file exists
 */
function render_tpl( $tpl_filepath, $options = array())
{
    //      Fugly global scope mayhem :3
    //      (to access any global var from within any tpl to render)
    extract( $GLOBALS );
    
    //      Overridable defaults
    $options += array(
        'prefix' => '',
        'suffix' => '',
    );
    
    //      Using output buffer
    ob_start();
    include $tpl_filepath;
    $markup = ob_get_contents();
    ob_end_clean();
    
    
    //      Markdown Extra support
    $tpl_ext = substr( $tpl_filepath, strrpos( $tpl_filepath, '.' ));
    if ( $tpl_ext == '.md' )
    {
        //      Fix relative paths for images
        //      might as well parse them directly while we're at it...
        //      Note: relative paths are based on the actual tpl file path
        //      @example :
        //          ![test alt text](file.jpg)
        //      becomes :
        //          <img src="physical/path/to/file.jpg" alt="test alt text" />
        $matches = array();
        $feedback = preg_match_all( '`!\[([^\]]?)\]\(([^\)]+)\)`Ui', $markup, $matches, PREG_SET_ORDER );
        
        if ( $feedback && !empty( $matches ))
        {
            $img_relative_path_prefix = $base_path . substr( $tpl_filepath, 0, strrpos( $tpl_filepath, '/' ));
            
            foreach( $matches as $match )
            {
                //      Exclude absolute paths
                if ( !empty( $match[ 2 ])
                    && substr( $match[ 2 ], 0, 7 ) != 'http://'
                    && substr( $match[ 2 ], 0, 8 ) != 'https://'
                    && substr( $match[ 2 ], 0, 1 ) != '/' ) {
                    $markup = str_replace( $match[ 0 ], '<img src="'. $img_relative_path_prefix .'/'. $match[ 2 ] .'" alt="'. addcslashes( $match[ 1 ], '"' ) .'" />', $markup );
                }
            }
        }
        
        //      Parse the rest
        $parsedown_extra = new ParsedownExtra();
        $markup = $parsedown_extra->text( $markup );
    }
    
    
    //      Allow (optional) prefix and/or suffix insertion
    $markup = $options[ 'prefix' ] . $markup;
    $markup .= $options[ 'suffix' ];
    
    return $markup;
}


