//我们提供了一个类： 
//
// public class Foo {
//  public void first() { print("first"); }
//  public void second() { print("second"); }
//  public void third() { print("third"); }
//} 
//
// 三个不同的线程将会共用一个 Foo 实例。 
//
// 
// 线程 A 将会调用 first() 方法 
// 线程 B 将会调用 second() 方法 
// 线程 C 将会调用 third() 方法 
// 
//
// 请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。 
//
// 
//
// 示例 1: 
//
// 输入: [1,2,3]
//输出: "firstsecondthird"
//解释: 
//有三个线程会被异步启动。
//输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。
//正确的输出是 "firstsecondthird"。
// 
//
// 示例 2: 
//
// 输入: [1,3,2]
//输出: "firstsecondthird"
//解释: 
//输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。
//正确的输出是 "firstsecondthird"。 
//
// 
//
// 提示： 
//
// 
// 尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。 
// 你看到的输入格式主要是为了确保测试的全面性。 
// 
// 👍 224 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Foo
{
// 为了获得独占式的资源访问能力，相应的线程必须锁定mutex，这样可以防止其它线程也锁定该mutex。只有当线程 unlock 后，剩下的线程才能lock
// mtx.lock() 如果一个线程锁住，另一个线程，再调用 mtx.lock() 就会被挂起等待
// 所以初始化 mtx1.lock()、mtx2.lock(),  printFirst() 后加 mtx1.unlock()  mtx1.lock() printSecond() mtx1.unlock() mtx2.unlock()  mtx2.lock() printThird() mtx2.unkock()
//
// 注意：
// 你应该确保 mutex 对象调用lock后，即使发生异常也会调用unlock，否则有可能造成资源被永远锁住或者死锁。
// 所以使用 lock_guard<mutex> lg(mtx1) 进行加锁

private:
    mutex mtx1;
    mutex mtx2;

public:
    Foo()
    {
        mtx1.lock();
        mtx2.lock();
    }

    void first(function<void()> printFirst)
    {

        printFirst();
        mtx1.unlock();
    }

    void second(function<void()> printSecond)
    {
        lock_guard<mutex> lg(mtx1);{
            printSecond();
        };
        mtx2.unlock();

    }

    void third(function<void()> printThird)
    {

        lock_guard<mutex> lg2(mtx2);{
            printThird();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
