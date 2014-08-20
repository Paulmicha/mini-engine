Mini-engine
===========

Non-modern, simple use of Php here - see [http://www.phptherightway.com/](http://www.phptherightway.com/) or [The League of Extraordinary Packages](http://thephpleague.com/) for anything serious :)  

## Motivation :
I still come back to this from time to time for quick & small tasks, so I thought I might as well clean it up & leave it here.

## Has been & could be used :
- for Tiny projects (this is not a CMS - no admin, login, etc.)
- as a Prototyping tool
- as a Front-end / Php code playground & "crashtest"
- for Tiny headless web services (REST)
- for Data migration "preprocessing"
- for Batch operations (see repo [mini-engine.bashpad](https://github.com/Paulmicha/mini-engine.bashpad "mini-engine.bashpad"))
- as a Bash commands store & launchpad (over SSH using PhpSeclib) - moved to  [mini-engine.bashpad](https://github.com/Paulmicha/mini-engine.bashpad "mini-engine.bashpad") repo.

## How
Structure :
```
project-root-dir/
├── config/
│   └── settings.inc        <-- edit settings here
├── engine/
│   ├── core/
│   │   ├── router.inc
│   │   ├── render.inc
│   │   └── ...
│   ├── vendor/
│   ├── writeable/
│   │   └── filecache/      <-- must be writeable by php (optional)
│   └── bootstrap.inc
├── routing/
├── theme/
│   ├── _assets/
│   │   ├── css
│   │   │   └── main.css
│   │   ├── js
│   │   │   └── main.js
│   │   └── vendor/
│   ├── _components/         <-- custom components (optional) e.g. used with render_tpl()
│   │   ├── vendor/
│   │   └── ...
│   ├── page.tpl.php
│   ├── index.tpl.php
│   └── ...
├── .htaccess                <-- requires Apache
├── favicon.ico
├── front_controller.php
└── ...
```
