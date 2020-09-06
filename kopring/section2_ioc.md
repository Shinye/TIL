# Spring IoC (Inversion of Control)

제어권이 뒤바뀌었다!

### 일반적인 (의존성에 의한) 제어권: "내가 사용할 의존성은 내가 만든다"

우리가 흔히 알고있는 방식은, 내가 사용할 의존성은 내가 직접 만드는 방식이다. (객체를 다음과 같이 직접 생성해준다던가...)

```java
class OwnerController {
	private OwnerRepository repo = new OwnerRepository();
}
```



### IoC: "내가 사용할 의존성? 누군가 알아서 주겠찌.. ㅇㅅㅇ"

- 내가 사용할 의존성의 타입(or 인터페이스) 만 맞으면 무엇이든 상관없다.
- 테스트의 편의를 위함도 있음
- Spring에서 주로 쓰이는 개념인 DI (Dependency Injection) 도 IoC의 일종이다.

```java
class OwnerController {
	private OwnerRepository repo;
	
	public OwnerController(OwnerRepository repo) { // 이게 IoC. 다음과 같이 외부에서 인자로 받는다.
		this.repo = repo;	
	}
	
	// using repo...
}
```



bean: 스프링이 관리하는 객체들



## IoC container

- bean을 만들고
- bean들 사이의 의존성을 엮어주며
- 컨테이너가 가지고 있는 bean들을 제공한다.

ApplicationConetxt: BeanFactory를 상속받음

- IntelliJ에서 해당 클래스가 bean으로 등록되어있는지 알고 싶다면, 코드 왼쪽에 다음과 같은 표시를 확인하면 된다. :eyes:
- annotation이 붙어있거나, 직접 빈으로 등록하거나 (@Bean annotation), 특정 interface를 상속을 받거나 ...

- bean에 등록되어있는 것들은 서로간의 의존성 주입을 해줄 수 있다.

  - 아래 예시의 코드에서, 생성자의 인자에 객체를 넣어주는 주체: spring IoC container (Application Context) 가 해당 타입의 bean을 찾아서 넣어주는 것.

    ```java
    class OwnerController {
    	private final OwnerRepository owners;
    	
    	public OwnerController(OwnerRepository clinicService) {
    		this.owners = clinicService;
    	}
    }
    ```

  - 단, 의존성 주입은 bean끼리만 가능하다. (스프링 IoC 컨테이너 안에 있는 객체들끼리만 가능)



## Bean





### @Autowired

```java
@Autowired
ApplicationContext applicationContext;

@Text
public void getBean() {
	OwnerController bean = applicationContext.getBean(OwnerController.class);
	assertThat(bean).isNotNull(); // maybe true...
}
```

- 생성자나 세터 등을 사용하여 의존성 주입을 하려고 할 때, IoC컨테이너 안에 담긴 bean들 중, 각 상황의 타입에 맞는 해당 빈을 찾아서 주입해주는 annotation

  

