{  
    "targets": [  
        {  
            "target_name": "addon",  
            "cflags": [
                "-std=c++11",
            ],
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "defines": ["NAPI_CPP_EXCEPTIONS"],
            "xcode_settings": {
                "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
            }, 
            "sources": [
                "./binding/event_loop.cc",
            ],
            "include_dirs": [
                "src",
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'dependencies': [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            'cflags!': [ '-fno-exceptions' ],
            'cflags_cc!': [ '-fno-exceptions' ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS'],
            'conditions': [
                [
                    'OS=="mac"', {
                        'xcode_settings': {
                            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
                        }
                    }
                ]
            ]
        }  
    ]  
}
