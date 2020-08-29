# 18870 좌표 압축

([문제 링크](https://www.acmicpc.net/problem/18870))

## 문제 풀이

해당 출력 결과는 좌표들을 중복 없이 오름차순으로 정렬하였을 때 순서와 같다.

STL map은 key를 기준으로 자동으로 정렬해주기 때문에, 이를 이용하여 vector에 push함과 동시에 map에 insert해준 뒤 정렬된 map을 순회하며 value에 순번을 삽입하였다.

이후 vector를 순회하며 map에서 해당 값들을 key로 value를 찾아주면 결과가 나오게 된다.