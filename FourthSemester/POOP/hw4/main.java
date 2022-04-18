import java.lang.Math;

class SquareMatrix {
  private int data[][];
  public int size;

  public SquareMatrix(int n) {
    this.size = n;
    this.data = new int[n][n];
  }

  public SquareMatrix(SquareMatrix s) {
    this.data = s.getData();
    this.size = s.size;
  }

  public int[][] getData() {
    return this.data;
  }

  public void setData(int[][] data) {
    this.data = data;
  }

  public String toString() {
    String res = "";

    for(int i = 0; i < this.size; i++) {
      for(int j = 0; j < this.size; j++) {
        res += this.data[i][j];
        res += " ";
      }
      res += "\n";
    }

    return res;
  }

  public int findMaxSum() {
    int maxSum = 0;
    int sum;

    for(int i = 0; i < this.size - 1; i++) {
      for(int j = 0; j < this.size - 1; j++) {
        sum = 0;
        sum += this.data[i][j];
        sum += this.data[i][j+1];
        sum += this.data[i+1][j];
        sum += this.data[i+1][j+1];
        if (sum > maxSum) {
          maxSum = sum;
        }
      }
    }

    return maxSum;
  }

  public void printAll() {
    System.out.println(this.toString());

    int max = this.findMaxSum();
    int sum;

    System.out.println(max);

    for(int i = 0; i < this.size - 1; i++) {
      for(int j = 0; j < this.size - 1; j++) {
        sum = 0;
        sum += this.data[i][j];
        sum += this.data[i][j+1];
        sum += this.data[i+1][j];
        sum += this.data[i+1][j+1];
        if (sum == max) {
          System.out.println("[" + i + "," + j + "]");
        }
      }
    }
  }
}

class SquareMatrixTest {
  public static void main(String[] args) {
    int size = (int)(Math.random() * 11) + 2;

    SquareMatrix s = new SquareMatrix(size);
    int data[][] = new int [size][size];

    for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
        data[i][j] = (int)(Math.random() * 9);
      }
    }

    s.setData(data);
    s.printAll();
  }
}