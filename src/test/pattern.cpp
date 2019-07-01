
#include <cstring>
#include <pthread.h>

class Singleton {
private:
    static Singleton *m_instance;
    Singleton() {}
    class Garbo { //它的唯一工作就是在析构函数中删除CSingleton的实例
    public:
        ~Garbo() {
            if( Singleton::m_instance )
                delete Singleton::m_instance;
        }
    };
    static Garbo garbo; //定义一个静态成员，程序结束时，系统会自动调用它的析构函数

public:
    static Singleton *getInstance();
};
//需要初始化
Singleton* Singleton::m_instance = NULL;

Singleton *Singleton::getInstance() {
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    if(NULL == m_instance) {
        pthread_mutex_lock(&mutex);//借用其它类来实现，如boost
        if(NULL == m_instance) {
            m_instance = new Singleton();
        }
        pthread_mutex_unlock(&mutex);
    }
    return m_instance;
}

class SingletonInside {
private:
    SingletonInside() {}
public:
    static SingletonInside getInstance() {
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&mutex);//借用其它类来实现，如boost
        static SingletonInside instance;
        pthread_mutex_unlock(&mutex);//借用其它类来实现，如boost
        return instance;
    }
};

class SingletonStatic {//饿汉模式
private:
    static const SingletonStatic *m_instance;
    SingletonStatic() {}
public:
    static const SingletonStatic *getInstance() {
        return m_instance;
    }
};
//外部初始化 before invoke main
const SingletonStatic *SingletonStatic::m_instance = new SingletonStatic();



