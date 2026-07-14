### `<string.h>` 주요 문자열 처리 함수 (외부 지식)

| 함수명 | 기본 형태 | 기능 설명 |
| :--- | :--- | :--- |
| **`strcpy`** | `strcpy(dest, src)` | `src` 문자열을 `dest` 변수에 복사합니다. |
| **`strncpy`** | `strncpy(dest, src, n)` | `src` 문자열에서 최대 `n`개의 문자만 `dest` 변수에 복사합니다. |
| **`strcat`** | `strcat(dest, src)` | `dest` 문자열의 끝에 `src` 문자열을 이어 붙입니다. |
| **`strncat`** | `strncat(dest, src, n)` | `dest` 문자열의 끝에 `src` 문자열을 최대 `n`개까지만 이어 붙입니다. |
| **`strcmp`** | `strcmp(s1, s2)` | 두 문자열 `s1`과 `s2`를 사전순으로 비교합니다. (같으면 0, 다르면 양수 또는 음수 반환) |
| **`strncmp`** | `strncmp(s1, s2, n)` | 두 문자열을 최대 `n`개의 문자까지만 비교합니다. |
| **`strlen`** | `strlen(s)` | 문자열 `s`의 길이(NULL 문자 제외)를 구하여 반환합니다. |
| **`strchr`** | `strchr(s, c)` | 문자열 `s`에서 특정 문자 `c`가 처음으로 나타나는 위치(포인터)를 찾아 반환합니다. |
| **`strstr`** | `strstr(s1, s2)` | 문자열 `s1` 안에서 부분 문자열 `s2`가 처음으로 나타나는 위치(포인터)를 찾아 반환합니다. |
