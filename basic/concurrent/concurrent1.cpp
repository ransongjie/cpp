#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

/**
 * g++ concurrent1.cpp -lpthread -o concurrent1.o
 * ./concurrent1.o
 */

/**
 * 任务函数无参数，线程无参数
 */
void *hello1(void *args)
{
    cout << "Hello" << endl;
    return 0;
}
void test1()
{
    pthread_t tids[5];
    for (int i = 0; i < 5; ++i)
    {
        // 参数依次是：创建的线程id，线程参数，调用任务函数，任务函数参数
        int ret = pthread_create(&tids[i], NULL, hello1, NULL);
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    // 主线程，等待任务线程结束
    pthread_exit(NULL);
}

/**
 * 任务函数有参数，线程无参数
 */
void *hello2(void *threadid)
{
    // 强制类型转换
    int tid = *((int *)threadid);
    cout << "Hello! 线程 ID: " << tid << endl;
    //    pthread_exit(NULL);
    return 0;
}
void test2()
{
    pthread_t threads[5];
    int threadIds[5];
    int rc;
    for (int i = 0; i < 5; i++)
    {
        cout << "test2(): 创建线程, " << i << endl;
        threadIds[i] = i;
        rc = pthread_create(&threads[i], NULL, hello2, (void *)&(threadIds[i]));
        if (rc)
        {
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

/**
 * 任务函数有参数（结构体参数），线程无参数
 */
struct duty_data
{
    int thread_id;
    char *message;
};
void *hello3(void *threadarg)
{
    struct duty_data *my_data = (struct duty_data *)threadarg;
    cout << "Thread ID : " << my_data->thread_id
         << ", Message : " << my_data->message << endl;
    pthread_exit(NULL);
}
void test3()
{
    pthread_t threads[5];
    struct duty_data dd[5];
    int rc;
    for (int i = 0; i < 5; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        dd[i].thread_id = i;
        dd[i].message = (char *)"duty message";
        rc = pthread_create(&threads[i], NULL, hello3, (void *)&dd[i]);
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

/**
 * pthread_join 阻塞调用线程直到被调用线程执行完成
 */
void *hello4(void *t)
{
    long long tid = (long long) t;//
    cout << "Sleeping in thread " << endl;
    sleep(1);
    cout << "Thread with id: " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}
void test4()
{
    int rc;
    int i;
    pthread_attr_t attr;
    pthread_t threads[5];
    void *status;

    // 初始化属性
    pthread_attr_init(&attr);
    // 设置线程为可连接的（joinable）
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // 创建线程
    for (i = 0; i < 5; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, hello4, (void *)&i);
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // 删除属性
    pthread_attr_destroy(&attr);
    for (i = 0; i < 5; i++)
    {
        // 阻塞调用线程直到被调用线程执行完成，这里阻塞了主线程
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}

int main()
{
    test4();
}