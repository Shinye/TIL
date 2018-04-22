# A Complete Guide to Flexbox

> 처음에는 공부한 내용을 간략하게 쓰려고 했는데, [CSS-TRICK 의 flex](https://css-tricks.com/snippets/css/a-guide-to-flexbox/) 글이 너무 좋아 이 글에 대한 번역 글이 되었습니다...



## Flexbox 란?

`Flexbox layout` 이란 CSS의 display 속성 중 하나로, 컨테이너들의 `레이아웃` , `정렬` , 그리고 `간격을 설정` 하는 데에 효과적이다.  <br>다루고자 하는 아이템들의 `사이즈를 모르거나 크기가 유동적이여야 하는 상황` 에서 유용하게 사용될 수 있다.

Flex의 핵심 아이디어는 화면 크기에 맞춰, 화면 안 아이템들의 넓이/높이를 가장 최적의 길이로 맞춰준다는 점이다. 따라서 디바이스의 화면 크기에 따라 유동적으로 아이템들의 크기를 조정할 수 있다. 그래서 이 속성의 이름이 flex이고, 이러한 특징은 flexible의 뜻과 일맥상통하다. 

또한 수평적으로만  배치되는 것이 원칙인 일반적인 레이아웃(block, inline..)과 달리, flexbox 레이아웃은 방향에 대해 조금 더 유연하다. 그리고 기존의 일반적인 레이아웃은 정적인 페이지에 대해서는 잘 작동하지만, 크거나 복잡한 어플리케이션(특히 방향 변경, 크기 조정, 늘리기, 축소 등) 에 대한 대응은 상대적으로 부족하다.

> Flexbox는 작은 크기의 레이아웃이나 모바일 디바이스에 적합하고, 큰 스케일의 레이아웃을 원한다면 `Grid` 속성을 사용하는 것이 좋다.



## Flex의 주요 요소들

(당연한 이야기지만) `display: flex` 를 설정한 컨테이너의 child들 역시 모두 flex 속성을 가지게 된다.

![](https://css-tricks.com/wp-content/uploads/2014/05/flex-container.svg)

![](https://css-tricks.com/wp-content/uploads/2014/05/flex-items.svg)

### flex-direction

![](https://css-tricks.com/wp-content/uploads/2013/04/flex-direction2.svg)

이 속성은 아이템 정렬의 주축(main-axis), 즉 flex item들이 정렬 될 방향을 설정한다. `row`는 x축 정렬이고 `column` 은 y축 정렬이다.

```css
.container {
  flex-direction: row | row-reverse | column | column-reverse;
}
```



### order

일반적으로 아이템들의 정렬은 배치 순서에 따라 이루어진다. 하지만 flex 속성을 가진 컨테이너는 order속성을 통해 우선순위를 자리 수 있다.

```css
.item {
  order: <integer>; /* default is 0 */
}
```

![](https://css-tricks.com/wp-content/uploads/2013/04/order-2.svg)



### flex-wrap

![](https://css-tricks.com/wp-content/uploads/2014/05/flex-wrap.svg)

flex의 디폴트 특징대로라면, 아이템 개수가 늘어나면 아이템의 크기가 줄어들며 어떻게든 단일한 줄에 포함시킬 것이다. 하지만 flex-wrap 설정을 해주면 줄바꿈이 일어난다.