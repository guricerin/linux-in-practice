#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define BUFFER_SIZE 1000
#define ALLOC_SIZE (100 * 1024 * 1024) // 100MB

static char command[BUFFER_SIZE];

// メモリ割り当ての様子を確認
int main(void)
{
    pid_t pid;
    pid = getpid();
    // このプロセスのメモリマップ情報を表示するコマンド
    snprintf(command, BUFFER_SIZE, "cat /proc/%d/maps", pid);
    puts("*** memory map before memory allocation ***");
    fflush(stdout);
    system(command);

    void *new_memory;
    // カーネルに対して新規メモリを要求
    new_memory = mmap(NULL, ALLOC_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_memory == (void *)-1)
    {
        err(EXIT_FAILURE, "mmap() failed");
    }

    puts("");
    printf("*** succeeded to allocate memory: address = %p; size = 0x%x ***\n", new_memory, ALLOC_SIZE);
    puts("");

    puts("*** memory map after memory allocation ***");
    fflush(stdout);
    system(command);

    if (munmap(new_memory, ALLOC_SIZE) == -1)
    {
        err(EXIT_FAILURE, "munmap() failed");
    }
    exit(EXIT_SUCCESS);
}
