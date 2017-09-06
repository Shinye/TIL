# Gulp

> gulp is a toolkit for automating painful or time-consuming tasks in your development workflow, so you can stop messing around and build something.

[gulp](https://gulpjs.com/)란 프론트엔드 자동화 빌드 툴이다.<br>일일이 반복해서 하기 번거로운 작업들(파일 minification작업, sass파일 컴파일, Lint 등)을 자동화하여 개발 시간을 단축시켜주는 역할을 하는 것이다. 프론트엔드 개발을 하며 필요한 각종 기능들이 gulp에서 플러그인으로 제공되어 확장성 있는 작업이 가능하다 (현재 980여개의 플러그인이 존재한다고 한다.)



## 시작하기

### gulp 설치

```shell
$ npm init
$ sudo npm install -g gulp
```

<br>

### gulp와 gulp-util을 devDependencies로 모듈 설치

gulp-util : gulp에서 로그를 쉽게 기록 할 수 있게 해준다.

```shell
$ npm install --save-dev gulp gulp-util
```

<br>

### gulp에서 ES6를 사용하고 싶다면

```shell
$ npm install --save-dev babel-core babel-preset-es2015
```

<br>

### `.babelrc` 파일 생성

```shell
{
  "presets": ["es2015"]
}
```

이처럼 .babelrc파일을 생성해도 되지만 `package.json` 에 babel을 추가해도 된다. 방법은 다음과 같다.

```shell
... ,
"babel": {
  "presets": [
    "es2015"
  ]
},
```

<br>

### gulpfile.babel.js 작성

gulpfile은 gulp에서 어떤 작업을 할 지 정의해줍니다. ES6문법을 써 작성해도 babel이 변환해줘서 괜찮습니다.

```javascript
'use strict';

import gulp from 'gulp';
import gutil from 'gulp-util'; 

gulp.task('default', () => {
    return gutil.log('Gulp is running');
});
```

gulp.task에서 'default' 는 말 그대로 default값으로써, 터미널에 `$ gulp` 라고 명령어를 실행하였을 때 'default' 라고 네이밍된 task를 돌린다. 뒤에 다시 작성되겠지만 특정 task를 실행하고 싶다면 `$ gulp [task명]` 을 쓰면 된다.

<br>

### 예제 디렉토리 구조

```
gulp-es6-webpack/
├── .babelrc
├── dist
├── node_components
├── server
│       └── main.js
└── src
    ├── css
    │    └── style.css
    ├── images
    │      └── image.png
    ├── index.html
    └── js
        └── main.js
├── gulpfile.babel.js
├── index.js
├── package.json
```

- src 폴더 : Front-end 사이드에서 사용할 파일들. gulp는 여기의 파일들을 minify하여 `dist` 폴더에 저장 될 것이다.
- dist폴더 : '배포' 라는 뜻을 가진 distribute의 약자. gulp의 자동화 과정이 거쳐진 후 저장되는 디렉토리로, 파일들이 라이브 서버에 올리기에 최적화 되어 있다. 


<br>


## API

gulp의 주요 API로는 크게 네 가지가 있다.

- `gulp.task`
- `gulp.src`
- `gulp.dest`
- `gulp.watch`



### 1. gulp.task(name [, deps, fn])

gulp에서 가장 핵심적인 API로써, gulp가 처리할 작업(task)들을 정의합니다.

📌 **인수 설명**

- **name** : string형태 / task의 이름
- (생략가능) **deps** : task name 의 배열 형태이며 이 인수가 전달 될 시, 이 배열 안에 있는 task들을 먼저 실행 한다음에, 함수형태로 전달되는 fn을 실행
- (생략가능) **fn** : 해당 task가 실행 할 함수.


<br>


### 2. gulp.src(globs[, options])

gulp가 어떤 파일들을 읽을지 정의한다.

📌 **인수 설명**

- **globs** : string 형태 혹은 array 형태 /  [node-glob syntax](https://github.com/isaacs/node-glob) 를 사용하여 “**/*.js” 이런식으로 여러 파일을 한꺼번에 지정
- (생략가능) **options** : Object형태 / glob에 전달 할 옵션. 


<br>

### 3. gulp.dest(path[, options])

gulp task를 마친 파일들이 어디에 저장될지 정한다. (도착지라는 의미의 destination의 약자.)

📌 **인수 설명**

- **path** : 지정할 디렉토리
- (생략가능) **options** : Object형태 / { cwd: ~ , mode: ~ } 형태<br>
  **cwd** 는 현재 디렉토리 위치(Current working directory)로서 .path가 /build/ 이런식으로 상대적일때 현재 디렉토리를 따로 설정하고 싶을 때 사용<br>
  **mode** 는 파일권한 (기본 : “0777”)

<br>

### 4. gulp.watch(glob[, opts], tasks/cb)

gulp.src에서 전달 된 glob에 해당하는 파일들을 주시하고 있다가, 변동이 있을 시 `tasks` 를 실행한다.

📌 **인수 설명**

- **glob** : glob에 해당하는 파일들을 주시하고 있다가, 변동이 있을 시 `tasks` 를 실행한다.
- **tasks** : task **name**의 배열형태 / 배열 형태가 아닐 땐 **event**를 파라미터로 가지고있는 콜백함수 **cb **를 작성.
- (생략가능) **opts** : gulp에서 사용하는 라이브러리인 [gaze](https://github.com/shama/gaze) 에 전달 할 옵션.

gulp 매뉴얼에 적힌 예제는 다음과 같다.

```javascript
var watcher = gulp.watch('js/**/*.js', ['uglify','reload']);
watcher.on('change', function(event) {
  console.log('File ' + event.path + ' was ' + event.type + ', running tasks...');
});

// OR

gulp.watch('js/**/*.js', function(event) {
  console.log('File ' + event.path + ' was ' + event.type + ', running tasks...');
});
```

<br>



## 플러그인 활용하기

FE개발을 하며 아주 자주 사용되는 플러그인들

- [gulp-uglify](https://www.npmjs.com/package/gulp-uglify/)
- [gulp-clean-css](https://www.npmjs.com/package/gulp-clean-css/)
- [gulp-htmlmin](https://www.npmjs.com/package/gulp-htmlmin/)
- [gulp-imagemin](https://www.npmjs.com/package/gulp-imagemin/)
- [del](https://www.npmjs.com/package/del) : del 모듈은 gulp 플러그인은 아니다. gulp 플러그인으로 제작된 모듈이 아니더라도 gulpfile 내에서 사용 할 수는 있음. 이 모듈은 특정 디렉토리를 삭제해주는 플러그인. 동기식으로 삭제 할 수 있는 기능을 가지고 있어 gulp 작업이 실행 될 때 마다 기존 dist 디렉토리에 있는 파일들을 삭제해줘야 하기 때문에 이 플러그인을 사용함.

위의 플러그인을 활용해서 gulpfile을 수정하면 다음과 같이 작성할 수 있겠다.

```javascript
// gulpfile은 gulp에서 어떤 작업을 할지 정의해줌.

'use strict';

import uglify from 'gulp-uglify';
import cleanCSS from 'gulp-clean-css';
import htmlmin from 'gulp-htmlmin';
import imagemin from 'gulp-imagemin';
import del from 'del';
import gulp from 'gulp';
import gutil from 'gulp-util';


gulp.task('default', ['clean','js','css','html', 'watch'], () => {
    return gutil.log('Gulp is running');
});

// 디렉토리 정의 : 소스/빌드 디렉토리를 담은 객체
const DIR = {
    SRC: 'src',
    DEST: 'dist'
};

const SRC = {
    JS: DIR.SRC + '/js/*.js',
    CSS: DIR.SRC + '/css/*.css',
    HTML: DIR.SRC + '/*.html',
    IMAGES: DIR.SRC + '/images/*'
};

const DEST = {
    JS: DIR.DEST + '/js',
    CSS: DIR.DEST + '/css',
    HTML: DIR.DEST + '/',
    IMAGES: DIR.DEST + '/images'
};

// task 정의
gulp.task('js', () => {
    return gulp.src(SRC.JS)
           .pipe(uglify())
           .pipe(gulp.dest(DEST.JS));
});

gulp.task('css',() => {
    return gulp.src(SRC.CSS)
            .pipe(cleanCSS({compatibility: 'ie8'}))
            .pipe(gulp.dest(DEST.CSS));
});

gulp.task('html', () => {
    return gulp.src(SRC.HTML)
            .pipe(htmlmin({collapseWhitespace: true}))
            .pipe(gulp.dest(DEST.HTML))
});

gulp.task('clean', () => {
    return del.sync([DIR.DEST]);
});

gulp.task('watch', () => {
    let watcher = {
        js : gulp.watch(SRC.JS, ['js']),
        css : gulp.watch(SRC.CSS, ['css']),
        html : gulp.watch(SRC.HTML, ['html']),
    };

    let notify = (event) => {
        gutil.log('File', gutil.colors.yellow(event.path), 'was', gutil.colors.magenta(event.type));
    };

    for(let key in watcher) {
        watcher[key].on('change', notify);
    }
});
```

<br>


### 참고 URL

[[Gulp.js] Gulp 입문 ① - Gulp에 대한 소개](http://programmingsummaries.tistory.com/356)<br>[12.1 편: GULP – JavaScript 빌드 자동화툴 알아보기 + ES6 문법으로 사용해보기](https://velopert.com/1344)<br>[12.2 편: GULP – 응용하기 (babel, webpack, nodemon, browser-sync)](https://velopert.com/1456)

