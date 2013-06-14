import java.util.concurrent.*;

class Concurrency {
    private static boolean stop;
    public static void main(String[] args)
    throws InterruptedException {
        Thread thread = new Thread(new Runnable() {
            public void run() {
                int i = 0;
                while (!stop) {
                    i++;
                    System.out.println("Waiting " + i);
                }
                System.out.println("Finished");
            }
        });
        thread.start();
        Thread.sleep(1);
        stop = true;
    }
}