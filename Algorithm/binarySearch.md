# 이진검색

[칸아카데미 알고리즘 강좌](https://ko.khanacademy.org/computing/computer-science/algorithms) 를 보고 공부하고 있습니다.

선형 배열에서 찾고자 하는 값을 찾을 때까지, 즉 후보 범위를 하나로 좁힐 때 까지, 찾고자 하는 값을 포함하는 리스트를 반으로 나누는 과정을 반복한다.

- 배열에서 어떤 항목(값)을 찾을 때,
- 추측값의 현 범위를 계속 파악하는 것

그림으로 표현한다면 다음과 같다.

![https://68.media.tumblr.com/10595b3dbb2eca2c44540a301364ea59/tumblr_oopdzkgro81w8w3y8o3_1280.png](https://68.media.tumblr.com/10595b3dbb2eca2c44540a301364ea59/tumblr_oopdzkgro81w8w3y8o3_1280.png)

![https://68.media.tumblr.com/c5bd22342d5ddbbed8ecc2b0c343ca19/tumblr_oopdzkgro81w8w3y8o2_1280.png](https://68.media.tumblr.com/c5bd22342d5ddbbed8ecc2b0c343ca19/tumblr_oopdzkgro81w8w3y8o2_1280.png)

![https://68.media.tumblr.com/7c5e97cc99a4dc835af84a5cee1e13ee/tumblr_oopdzkgro81w8w3y8o1_1280.png](https://68.media.tumblr.com/7c5e97cc99a4dc835af84a5cee1e13ee/tumblr_oopdzkgro81w8w3y8o1_1280.png)



이진검색 과정을 글로 써본다면 다음과 같다.

- 배열의 크기를 알아낸다.
- 찾고자 하는 값이 포함된 리스트 범위를 나타내는 min과 max 변수를 선언한다. 처음 min에는 배열의 첫 인덱스인 0, max에는 마지막 인덱스인 size-1
- 추측값은 min과 max의 평균이다.
- if 추측값 == 정답 : break
- else if 추측값 > 정답 : max = 추측값-1
- else (추측값 < 정답) : min = 추측값+1



코드로 작성하면 다음과 같다.

```c++
#include <iostream>
using namespace std;

int binarySearch(int answer, int *arr, int size){

    cout << "size : " << size << endl;
    int min = 0; int max = size-1;
    int avg;

    while(1){
        avg = (max+min)/2;
        cout << "avg : " << avg << endl;
        if(arr[avg] == answer){
            cout<< "found!" << endl;
            break;
        }
        else if(arr[avg] > answer){
            max = avg-1;
            cout << "max : " << max << endl;
        } else {
            min = avg+1;
            cout << "min : " << min << endl;
        }
    }
    return arr[avg];
}

int main(){
    int answer;
    cin >> answer;
    int arr[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    cout << binarySearch(answer, arr, 25) << endl;
}
```