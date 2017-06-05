# 정렬 커스터마이징

### 문제 상황

[https://github.com/Shinye/Algorithm-Study/blob/master/test_reverseNum.cpp](https://github.com/Shinye/Algorithm-Study/blob/master/test_reverseNum.cpp)

여러 개의 자연수를 표준 입력(standard input)에서 읽은 후, 그 수들을 이어붙여서 만들 수 있는 가장 큰 수와 가장 작은 수의 합을 구하세요.

- 주어지는 입력은 10개 이하이며, 각각 2자리 이하의 자연수입니다.
- 숫자는 공백으로만 구분됩니다.
- 숫자를 이어붙일 때 입력된 각 숫자들을 반드시 한 번씩 사용해야 합니다.

 [예시 1]<br> 입력이 1 2 3일 경우, 만들 수 있는 가장 큰 수는 321이고 가장 작은 수는 123이며 두 수의 합은 444이다. 

 [예시 2]<br>입력이 2 9 10 21 24일 경우, 만들 수 있는 가장 큰 수는 92422110이고, 가장 작은 수는 10212249이며 두 수의 합은 102634359이다. 



<br>

### 입력받은 여러 정수들로 만들 수 있는 가장 큰 수와 작은 수

처음에는 정수들을 string으로 입력받아 ASCII 기준으로 정렬을 하면 가장 앞의 자리수 기준으로 정렬이 되니 가장 큰 수와 작은수가 나오지 않을까 생각했다. (또한 처음엔 string이 아니라 char로 데이터형을 설정했는데, 그러니까 십의자리숫자 부터는 숫자가 하나밖에 나오지 않아서..ㅠㅠ string으로 데이터형을 지정했다.)

하지만 입력받은 수가 각각 10의자리 수/1의자리 수라면 <br> "24", "2", "21" 을 입력받으면 가장 작은 수를 만들기 위해선 "21", "2", "24" 의 순서로 나열이 되어야 하지만, ASCII기준으로 정렬을 하게 되면 "2", "21", "24" 의 순서로 정렬이 되게 된다. <br>이러한 이슈를 해결하기 위해 같은 최상단의 앞자리 수 (2,21,24처럼..)끼리의 비교는 자리수가 작은 건 다른 자리수가 긴 수와 맞춰서 비교를 해야한다…24,2,21을 비교할 때 2를 22로 놓고 비교를 하면 된다는 것이다. 이렇게 하면 해당 이슈를 해결할 수 있다.

```c++
// bool형태이며 인자에는 const를 반드시 붙여주어야 한다.
bool cmp_min(const string A, const string B){ // 가장 큰 수 만들기
    string tmpA = A, tmpB = B;
    
    if(tmpA.size() == 1){ // 다음의 조건은 숫자가 일의 자리 수일 때.
        tmpA += tmpA;
    }
    if(tmpB.size() == 1){
        tmpB += tmpB;
    }
    
    return tmpA < tmpB; // 오름차순 정렬
}

bool cmp_max(const string A, const string B){ // 가장 작은 수 만들기
    string tmpA = A, tmpB = B;
    
    if(tmpA.size() == 1){ 
        tmpA += tmpA;
    }
    if(tmpB.size() == 1){
        tmpB += tmpB;
    }
    
    return tmpA > tmpB; // 내림차순 정렬
}

```







