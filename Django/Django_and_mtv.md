#Django and MTV

!!!수정중!!! 빨리수정해!!!

MVC의 View와 MTV의 View는 전혀 상관이 없다. 오히려 MTV의 Template이 MVC의 View와 가깝다.
굳이 MVC의 Controler의 역할을 하는 것을 꼽자면 Django 그 자체가 MVC의 컨트롤러 역할을 한다. (공홈에 나와있음…원문 찾아보기…)

[브라우저] —request—> [HTTP Server] —wsgi(웹서버와 장고(urls.py)를 연결해주는 것)—> [Routing - urls.py // url dispatcher. url 파싱] —> [view : url routing을 처리하는 규칙]