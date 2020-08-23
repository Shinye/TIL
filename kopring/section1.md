[예제로 배우는 스프링 입문](https://www.inflearn.com/course/spring_revised_edition/dashboard) 수업을 듣고 공부한 내용을 정리합니다.



# Section1

### 프로젝트 실행방법

src/main/java/... /PetClinicApplication 실행

### 프로젝트 실행 시 로그 보는 방식

로그 설정 파일에 가서 로깅 옵션을 info레벨이 아닌 debug레벨로 바꿔본다.

- 로그 설정 파일 위치: `src/main/resources/application.properties` 
  - Logging 모드 값을 DEBUG모드로 변경

### DispatcherServlet ?

공부한 내용 정리 파일 따로 링크 걸 예정...



----

로그 내용을 확인해보니, Dispatcher 실행 후...

`s.w.s.m.m.a.RequestMappingHandlerMapping : Mapped to org.springframework.samples.petclinic.owner.OwnerController#initFindForm(Map)` 가 실행됨.

- initFindForm() 이 return 하는 것

  - view 이름에 해당한다.

- 디버거 다음으로 넘기고 싶으면 f9 클릭!

- redirect처리

  - Controller에서 클라이언트의 요청을 처리한 후 다른 페이지로 Redirect 하고 싶을 경우

    `return "redirect:/home";` 과 같이 처리



예시) Add owner페이지로 이동할 때...

- /owners/new url로 get 요청이 간다
- dispatcher servlet이 OwnerController에 있는 `@GetMapping('/owners/new')` annotation의 인자에 맞는 메소드를 호출해준다.



숙제) 코드 고쳐보기

⇒ LastName이 아니라 FirstName으로 검색

⇒ 정확하게 일치하는게 아니라 해당 키워드가 들어있는 걸 찾아보기

⇒ Owner에 age추가하기

