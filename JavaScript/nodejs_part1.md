# Node.JS와 Express 1

## nodeJS란?





## Express란?







## 실습 내용

### 실습 순서

1. Node.JS 설치

2. 필요한 모듈들을 다운받을 수 있는 **NPM** 설치. Node.js로 프로젝트를 하면 자연히 npm을 사용하게 되고 의존모듈들을 npm으로 설치해서 사용하게 되기 때문이다. 

3. 프로젝트를 진행할 디렉토리를 만든 후 `npm init` 명령어를 작성한다.

4. `Express` 를 설치한다. `npm install --save` 명령어로!<br>이 때, --save 는 **현재 설치한 내역을 `package.json` 파일에 등록하라는 뜻**이다. 프로젝트 소스가 모듈에 의존하고 있기 때문에 모듈의 버전에 따라서 문제가 생길 여지가 있기 때문에 의존성 모듈의 버전관리를 해줄 필요가 있다. npm은 프로젝트에 대한 설정을 package.json이라는 파일에 의존하고 있고, 이 파일에 JSON형식으로 작성해서 프로젝트에 대한 관리를 할 수 있다. <br> `dependencies` 항목에서 설치된 모듈들의 버전을 확인할 수 있다.

   ![https://drive.google.com/uc?id=0B3Or0Wv2t1xwb3RDejF2UE5ESnc](https://drive.google.com/uc?id=0B3Or0Wv2t1xwb3RDejF2UE5ESnc)





**app.js**

```javascript
var express = require('express');
var app = express();
var bodyParser = require('body-parser'); // 바디에 적힌 데이터들을 파싱해줌

app.listen(3000, function(){
    console.log("starting express server on port 3000!!!!");
}); // 3000번 포트를 접속하는거

app.use(express.static('public')); // use : 야 나 이거 쓸랭!!
app.use(bodyParser.json()); // http request body 안의 json 형태의 데이터를 json으로 파싱한다?
app.use(bodyParser.urlencoded({extended:true}));
app.set('view engine', 'ejs') // 나 view engine은 ejs쓸래!!!

// public폴더에 들어있는 모든 파일들을 static파일들로 간주해 아래와 같이 url 라우팅
// 을 처리하지 않아도 파일을 불러오는데 문제가 없도록 해주는 함수.

// url routing!!
app.get('/',function(req,res){
    //res.send('<h1>hello!!</h1>');
    res.sendFile(__dirname + "/public/main.html");
});

app.post('/email_post', function(req,res){ // HTTP POST요청으로 이 URL의(첫번째 인자) 내용을 가져오도록 만든다.
    // get : req.param('email')
    console.log(req.body.email); // email: 'nicole9111@naver.com' 의 형식으로 나오기때문에
    //res.send("<h1>hello "+req.body.email+"</h1>");
    res.render('email.ejs', {'email' : req.body.email});
});

app.post('/ajax_send_email', function(req,res){
    var responseData = {'result':'ok', 'email':req.body.email};
    res.json(responseData); // Sends a JSON response. 응답 메소드 : 응답을 클라이언트로 전송하고 요청-응답 주기를 종료할 수 있습니다. 라우트 핸들러로부터 다음 메소드 중 어느 하나도 호출되지 않는 경우, 클라이언트 요청은 정지된 채로 방치됩니다.
});
```

1. **Express에서의 라우팅**

   클라이언트로부터 특정 URI(또는 경로)와 특정 HTTP method에 대한 요청이 들어왔을 때, 애플리케이션이 응답하는 방법을 결정해 주는 것. 각 라우터는 하나 이상의 핸들러 함수를 가질 수 있다.

   라우터에는 다음과 같은 정의가 필요하다 : `app.METHOD(PATH, HANDLER)` 

   1) app은 Express의 인스턴스이다.<br>2) METHOD는 HTTP 메소드<br>3) PATH는 서버에서의 경로이다. 특정 URL(또는 경로)가 들어감. <br> 4) HANDLER는 라우트가 일치할 때 실행되는 함수. 애플리케이션이 요청에 응답하는 방법에 대해 작성한다.

   ​

2. **Express에서 정적 파일 사용**


   CSS, JavaScript, 이미지, 기타 파일 등의 정적 파일을 제공하려면 Express의 기본 제공 미들웨어 함수인 `express.static()` 함수를 사용하면 된다. 이걸 사용하면 굳이 URL 라우팅을 사용하지 않아도 된다. 예를 들면, 다음과 같은 코드를 이용하여 `public`이라는 이름의 디렉토리에 포함된 이미지, CSS 파일 및 JavaScript 파일을 라우팅 없이 사용하면 된다.

   ```javascript
   app.use(express.static('public'));
   app.use(express.static('file'));
   ```

3. **그 외**

   express가 제공하는 미들웨어 함수의 변수 중 `__dirname` 은 현재 파일의 디렉토리 위치를 알려준다. 




**form.html**

```html
<!DOCTYPE html>
<html>
  <head>
    <title>post test</title>
  </head>
  <body>
    <form action="/email_post" method="post"> <!--action:이메일포스트 폴더로 가라!-->
      email : <input type="text" name="email"><br/>
      <input type="submit">
    </form>

      <button class="ajaxsend">Ajax Send </button>

      <div class="result"></div>

      <script>
        document.querySelector('.ajaxsend').addEventListener('click', function(){
          var inputdata = document.forms[0].elements[0].value;
          sendAjax('http://127.0.0.1:3000/ajax_send_email', inputdata);
        })

        function sendAjax(url,data){
          var data = {'email' : data} // 클라이언트에 있는 form을 JSON형태로 만듦
          data = JSON.stringify(data); // JSON값을 문자열로 바꿔줌.
          var xhr = new XMLHttpRequest();

          //HTTP요청 구성 순서 : 요청방식,URL지정 -> 요청헤더 -> 요청본문 순서
          xhr.open('POST',url); 
          // app.js(서버) 에서 post로 받았기 때문에 포스트로 보냄. 
          // HTTP POST 요청으로, 이 url의 내용을 가져오도록 만든다.
          
          xhr.setRequestHeader('Content-Type', "application/json"); 
          //요청 헤더 설정 //서버로 보낼 때 제이슨 형태의 데이터를 보냄 -> 데이터 타입 써준거
          
          xhr.send(data); 
          // 부가적인 요청 '본문(body)'을 지정하고 서버로 전송하는 것 // send에 담아 보냄 
          // GET요청은 본문을 가질 수 없으므로 send()메서드의 인자를 null로.
          // 해당 본문은 setRequestHeader()에서 지정한 Content-Type 형식이어야 한다.

          xhr.addEventListener('load', function(){ // 응답이 제대로 왔을 때...로드 되었을 때.
            var result = JSON.parse(xhr.responseText); 
            // responsetext : HTTP응답을 모두 전송받았으면, 이 프로퍼티는 완전한 응답을 받는다.
            if(result.result !== 'ok') return;
            document.querySelector(".result").innerHTML = result.email;
          });
        }
      </script>
  </body>
</html>
```

1. **EventTarget.addEventListener('액션명', '해당 액션이 실행됐을 시 작동되는 함수')**

   EventTarget에서 불려질 특성 리스너를 등록하는 것이다. 해당 EventTarget에 들어갈 수 있는 종류로는

   - Element
   - Document
   - Window
   - XMLHttpRequest()

   등이 있다. XMLHttpRequest에 적용할 수 있는 액션명으로는 abort, error, load, loaded, loadstart, progress, timeout이 있다고 한다.

   ​

2. **Ajax 적용 프로세스**

   `XMLHttpRequest 객체` 는 클라이언트 측 자바스크립트가 웹 서버로 HTTP 요청을 보내고 응답을 받을 수 있도록 하는데 특화되었다.

   Ajax를 적용한 웹 애플리케이션의 핵심적인 특징은, http를 조작해 페이지를 다시 불러오지 않고도 웹서버와 데이터를 교환할 수 있다는 점이다. 페이지를 다시 로드하지 않아도 서버에 request를 전달하는 프로세스는 다음과 같다.

   `요청방식, URL 지정 -> 요청헤더 지정 -> 요청본문 순서 -> req/res가 성공적으로 이뤄졌는지 확인`

   *xhr : XMLHttpRequest의 인스턴스

   1) xhr.**open(METHOD, url)**

   URL과 요청방식을 지정하여 open()메소드를 호출한다. 우선, open 함수의 첫 번째 인자에는 서버에 보낼 request 방식인 http method를 작성한다. 두 번째 인자로는 요청을 보낼 주소를 작성한다.

   2) xhr.**setRequestHeader('string 헤더에 포함되는 변수명', 'string 값')**

   추가적인 요청 매개변수를 지정할 필요가 있다면 setRequestHeader() 를 호출한다.

   3) xhr.**send(body)**

   웹 서버로 준비된 HTTP 요청을 보내기 위한 send() 메서드를 호출한다. 이전에 open() 메서드를 호출한 적이 없거나, 더 일반적인 경우로 readyState가 1이 아니라면, send() 메서드는 예외를 발생시킨다.

   이 메서드에 전달인자는 http request 메세지 중 body 부분을 넘긴다. 만약 `GET`의 경우 처럼 body 부분에 전달 인자가 없는 경우에는, 인자를 비우거나 null로 보내도 된다.

   4) **xhr.addEventListener('load', function(){…})**

   본래 XMLHttpRequest 객체는 `onreadystatechange`라는 단 하나의 이벤트 핸들러 프로퍼티만 정의되어있었다.<br>하지만 최근 나온 XHR2에서는 훨씬 사용이 간편한 progress 이벤트 핸들러를 포함해 프로퍼트 목록을 확장했다. EventTarget 객체의 메서드를 사용함으로써 핸들러를 등록할 수 있다. XMLHttpRequest 이벤트는 항상 이 XHR 객체 자체에서만 발생된다. 



