#include <sys/types.h>
#include <unistd.h>

int main(void) {
    /* CPUがユーザモード、カーネルモードを交互に遷移していることを確認 */
    for (;;)
        getppid();
}
