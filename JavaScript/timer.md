# 자바스크립트 타이머

Javascript 를 이용할 때,<br>1) 종종 특정 함수나 기능을 페이지가 로드되거나 버튼이 클릭되었을 때, 바로 실행하지 않고, 약간의 시간이 지난후에 실행되게 하고 싶은 경우<br>2) 특정 함수를 지속적으로 반복하여 실행하고 싶은 경우도 있다.

예를 들면 특정 정보를 화면에 표시하여 사용자에게 안내하고, 5초 후에 다른 페이지로 이동시키고 싶은 것이라면 위의 첫번째 경우일 것이며, <br>10초마다 새로운 정보를 보여주기 위해 페이지의 특정 영역 프레임을 AJAX호출을 통해 지속적으로 갱신해주고 싶은 경우라면 두번째 경우일 것이다.

이런 처리를 위해 Javascript는 클라이언트 측 타이머 함수인 **setTimeout** 과 **setInterval** 함수를 제공하고 있다.



1. setTimeOut([function],[Milliseconds])

   - 특정 시간 이후, **단 한번만** 첫 번째 인자의 함수(코드)를 실행시킬 때 사용한다.
   - 두 번째 인자의 시간(Milliseconds)이 경과하면 첫 번째 인자의 함수 코드를 실행시킨다.

   ```javascript
   function foo(){
     setTimeOut(function(){ // 코드를 여기에 써도 되지만 외부에 함수가 있다면 함수명만 써줘도 된다.
     	alert("네이버 시작페이지로 이동합니다");
       location.href = "https://www.naver.com";
     },3000);  // 3초 후에 함수가 실행됨
   }
   ```



2. setInterval([function],[Milliseconds])

   - 특정 시간 마다 특정 함수 혹은 코드를 실행시킬 때 사용한다.

   - 두 번째 인자의 시간(Milliseconds)이 지날 때 마다 첫 번째 인자의 함수를 실행한다.

     ```javascript
     function foo(){
       var num = 0;
       setInterval(function(){
         num += 1;
       },3000);
     }
     ```



3. clearInterval([Timer Id])

   - setInterval함수를 종료시키고 싶을 때 `clearInterval` 함수를 사용하면 된다.

   - 대신 clearInterval을 하고 싶을 때 함수 인자로 종료하고자 하는 인터벌 함수 이름을 인자로 넣어주어야 한다.

     ```javascript
     var num = 0;
     var timeItv = setInterval(function(){ // 인터벌 함수에 변수명을 지정한다.
       num += 1;
     },3000);

     document.getElementById("stopIntervalButton").onclick = function(){
       clearInterval(timeItv);
     }
     ```



이러한 타이머함수를 활용해서 다음과 같은 코드를 작성할 수 있다.

2. ​

```html
<!--
	100px짜리 박스를 버튼을 누르면 3초간 움직이며 (200px,200px)로 옮겨지도록 만들기
-->

<!DOCTYPE html>
<html>
  <head>
    <style>
      body{
        margin:0;
        padding:0;
      }

      #box1{
        position:relative;
        width:150px;
        height:150px;
        background-color:pink;
        left:0px;
        top:0px;
      }
    </style>

    <script>
      var num = 0;
      var temp = 0;
      var plus = 200/3;

      function moving(){
          console.log("moving function clicked...");
          var itv = setInterval(function () {
              temp = temp+plus;
              document.getElementById("box1").style.left = temp+"px";
              document.getElementById("box1").style.top = temp+"px";
              num++;

              if(num == 3){
                  clearInterval(itv);
              }
          },1000);
      }

    </script>

  </head>
  <body>
    <button onclick="moving()">클릭</button>
    <br />

    <div id="box1">

    </div>
  </body>
</html>

```

