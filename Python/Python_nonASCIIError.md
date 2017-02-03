# Non-ASCII Character 관련된 한글 에러 문제

파이썬 기초 실습을 하던 중 컴파일 시 다음과 같은 에러가 났다.

![https://68.media.tumblr.com/736334eaeaa1761c93b9e2cdce850cc5/tumblr_oksaswBw7r1v80c66o1_1280.png](https://68.media.tumblr.com/736334eaeaa1761c93b9e2cdce850cc5/tumblr_oksaswBw7r1v80c66o1_1280.png)



`SyntaxError: Non-ASCII character '\xed' in file /Users/shinyesong/Inflearn_Django/models.py on line 5, but no encoding declared;`

파이썬의 경우 기본적인 설정 상태에서는 코드 내에 한글이 있는 경우 다음과 같은 오류가 난다. 코드 내에 한글을 파이썬이 읽어들이지 못해서 발생되는 에러라고 볼 수 있다.



### 해결방법

파일 최상단에 

```python
# -*- coding: utf-8 -*-
```

을 써주어 한글 인코딩에 문제가 없도록 하면 된다. euc-kr을 쓰고 싶을 땐 utf-8 자리에 대신 써주면 된다.<br>utf는 대문자 아니고 소문자로 써주기!