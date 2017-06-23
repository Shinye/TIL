# display 속성

> 모 기업 면접을 볼 때 display속성에 대해 너무 당당하게 헛소리를 해서 그 날의 창피함을 잊지 않기 위해 기록해둡니다…

 display속성은 css로 레이아웃을 제어할 때 가장 중요한 property이다.<br>모든 엘리먼트에는 엘리먼트 유형에 따라 기본 표시값(주로 `inline`, `block`)이 존재한다.



### 1. block 속성

block속성은 요소의 가로 길이가 100%가 된다. <br>width값을 직접 설정해도 **보이지 않는 margin이 남은 여백을 메워** 자동으로 줄바꿈이 가능하게 해준다. width, height, margin값을 모두 설정 가능하다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwZFFMVDBUYi1iN2s](https://drive.google.com/uc?id=0B3Or0Wv2t1xwZFFMVDBUYi1iN2s)



### 2. inline 속성

inline속성은 줄을 바꾸지 않고 다른 요소와 함께 한 행에 위치하려는 성향을 가지고 있다. 그래서 inline속성은 문장 안에서 사용하는 태그에 주로 기본값으로 설정되어 있다.<br> 요소에서 box model에서의 contents box부분만을 감싸고 있다. 이러한 이유로 inline속성의 요소에는(span, a 등) width와 height값을 설정할 수 없다. <br> 또한 `margin-top`, `margin-bottom`이 적용되지 않는다. inline 요소의 상-하 여백은 margin이 아닌 `line-height` 속성에 의해 발생한다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwODctbTA4UG5VLWs](https://drive.google.com/uc?id=0B3Or0Wv2t1xwODctbTA4UG5VLWs)

width, height, margin-top 속성이 반영되지 않았음을 알 수 있다.



### 3. inline-block 속성

inline-block 속성은 **inline속성 처럼 한 줄에 표현이 가능하면서도, margin/width/height 속성을 사용할 수 있다.** <br> 

- 상, 하단 외부 여백(margin-top, margin-bottom) 속성을 정의할 수 있다. `inline-block` 요소의 상, 하 여백을 `margin`과 `line-height` 두가지 속성 모두를 통해 제어할 수 있다.
- 너비(width)와 높이(height) 속성을 정의할 수 있다. 기본적으로는 태그가 품고 있는 내부 요소의 부피에 맞춰지지만, 너비와 높이를 지정하면 이 값 또한 표현된다.
- `inline-block` 속성을 가진 태그끼리 연속으로 사용되는 경우에는 최소한의 간격을 유지하기 위해서 좌, 우에 약 5px 가량의 외부 여백(margin)이 자동으로 발생한다다. 하지만, `margin-left`나 `margin-right`를 사용하면 여기에 추가로 여백을 줄 수 있게 된다.



### 4. none 속성

해당 속성이 적용된 요소는 보이지 않고 그 만큼의 자리도 차지하지 않는다. visibility:hidden 속성과 유사하지만 hidden값은 요소는 투명해지되 자리는 차지한다.