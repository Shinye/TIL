# NPM이란?

자바스크립트를 쓰기 시작하면서 자연스럽게 자주 사용하곤 하지만 정확하게 뭔지에 대해서는 대답하지 못하는 것 같아 기록합니다.

> npm is the package manager for JavaScript and the world’s largest software registry. Discover packages of reusable code — and assemble them in powerful new ways.
>
> Use npm to install, share, and distribute code; manage dependencies in your projects; and share & receive feedback with others.

공식 문서에 나와있는 설명과 같이 npm은 자바스크립트를 위한 패키지 매니저로, 설치/버전/ 호환성 관리 등이 가능하다.<br>또한 npm을 통해 설치한 모듈(패키지) 들은 [Common JS](https://github.com/Shinye/TIL/blob/master/JavaScript/module.md#모듈-포맷)의 문법 형식으로 불러와 쓸 수 있다. 형식은 다음과 같다.

```javascript
// npm install을 통해 다운받은 express를 사용하고 싶다면
var express = require('express');
```



## 설치 관련

설치 방법에 대한 구체적인 방법들은 후술할 예정이지만, 일단 설치를 위한 기본적인 문법은 다음과 같다.

```shell
# 설치
npm install [패키지명]
# 제거
npm uninstall [패키지명]
# 업데이트
npm update [패키지명]
```



### Local vs Global

- **Local** : `npm install $package` 명령어를 실행한 디렉토리 내에 설치가 된다. 이 설치 된 모듈은 해당 디렉토리 내의  `node_modules` 안에 저장된다.
- **Global** : `npm install -g $package` <br> local과는 달리 시스템 디렉토리 내에 설치해야 한다.<br>저장 되는 디렉토리 경로는 `/usr/local/lib/node_modules` 여기! 시스템 디렉토리에 저장해야하므로 명령어를 시작하기 전 `sudo` 를 붙여줘야한다.



### package.json 은 뭐하는 파일이지?

해당 디렉토리 내에 설치 된 패키지들의 속성을 정의하는 json파일이다. 이 프로젝트(해당 디렉토리)가 의존하고 있는 모듈들의 목록과 버전정보를 제공한다. 

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwX2lRX2xkQmtsSjA](https://drive.google.com/uc?id=0B3Or0Wv2t1xwX2lRX2xkQmtsSjA)



### dependencies vs devDependencies

- **dependencies**

  ```shell
  npm install --save [패키지명]
  ```

  > It means that you cannot use this npm module without it. It simply will not work unless you have this module installed.

  package.json 내의 `dependencies` 리스트에 들어간다.<br>내가 만든 프로젝트(my npm project) 를 다른 곳에서 사용할 때, 해당 리스트에 적힌 모듈이 설치되지 않으면 작동되지 않는다.

- **devDependencies**

  ```shell
  npm install --save-dev [패키지명]
  ```

  > It means that your npm plugin isn't dependent on it, however your development environments are dependent on it.

  package.json 내의 `devDependencies` 리스트에 들어간다.<br>내가 이 npm 프로젝트를 '개발' 하는 과정에서 꼭 필요한 패키지들이다. 반면 이 npm프로젝트를 배포한 후, 이 프로젝트를 npm install 하여 사용하는 다른 유저는 이 패키지들이 필요치 않다.

📌하지만! If you aren't publishing to npm, it technically doesn't matter which flag you use.



### 참고 URL

[[Node.JS] 강좌 05편: NPM](https://velopert.com/241)<br>[npm "dependencies" vs "devDependencies"](https://www.linkedin.com/pulse/npm-dependencies-vs-devdependencies-daniel-tonon)