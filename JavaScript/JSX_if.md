# JSX 안에서의 조건문

### if문

else나 else if가 없는 if문만 쓰고 싶을 경우 `&&` 키워드를 쓴다. 

```jsx
<div>
	{this.filter() === 'filter' && <span>this is filter</span>}
</div>
```



### if-else문

if-else문은 우리가 흔히 알고 있는 삼항연산자( `? :` )를 쓴다.

```jsx
<div>
	{this.filter() === 'filter' 
    ? <span>this is filter</span> 
    : <span>not a filter</span>}
</div>
```



### if-else if-else문

else-if의 부분은 삼항연산자의 `:` 뒤에 새로운 삼항연산자를 만들어 사용한다.

```jsx
<div>
  { this.filter() === 'filter1' ? <span>this is filter1</span> 
    : this.filter() === 'filter2' ? <span>this is filter2</span>
  	: <span>not a filter</span>
  }
</div>
```

