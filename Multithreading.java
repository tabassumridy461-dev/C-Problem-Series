class MyThread extends Thread {

    public void run() {

        for (int i = 1; i <= 5; i++) {

            System.out.println("Thread Running : " + i);

        }

    }

}

public class SimpleThreadExample {

    public static void main(String[] args) {

        MyThread thread = new MyThread();

        thread.start();

        System.out.println("Main Thread Finished.");

    }

}
