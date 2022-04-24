public class Main {
  public static void main(String[] args) {
    RouteCipher r = new RouteCipher(5);

    String cipherText = "abortthemissionyouhavebeenspotted";
    char [] cipherTextChars = cipherText.toCharArray(); // to char array 
    String text = new String(cipherTextChars); // to string

    String test = "123456789";

    System.out.println(r.encript(test));
  }
}

public class RouteCipher {
  private int key;
  private int cols;
  private int rows;
  private char[][] grid;

  private void fillGrid(char[] charArr) {
    this.cols = Math.abs(this.key);
    this.rows = (int)Math.ceil(charArr.length/(double)this.cols);
    this.grid = new char[this.cols][rows];
    
    for (int r = 0; r < this.rows; r++) {
      for (int c = 0; c < this.cols; c++) {
        int index = r*this.cols + c;
        if (index < charArr.length) {
          grid[c][r] = charArr[index];
        } else {
          grid[c][r] = 'X';
        }
      }
    }
  }

  public RouteCipher(int key) {
    this.key = key;
  }

  public int getKey() {
    return this.key;
  }

  public void setKey(int key) {
    this.key = key;
  }

  public String encript(String text) {
    this.fillGrid(text.toCharArray());

    return this.toString();
  }

  public String decript(String cipher) {
    return "todo";
  }
  
  public String toString() {
    String res = "";
    int col = this.cols-1;
    int row = this.rows;
    int currCol = this.key < 0 ? this.cols-1 : 0;
    int currRow = this.key < 0 ? this.rows-1 : -1;
    int modifier = this.key / Math.abs(this.key);

    while (row >= 0 && col >= 0) {
      for(int i = 0; i < row; i++) {
        currRow += modifier;
        res += this.grid[currCol][currRow];
        System.out.println(res);

      }
      row -= 1;

      for(int i = 0; i < col; i++) {
        currCol += modifier;
        res += this.grid[currCol][currRow];
        System.out.println(res);

      }
      col -= 1;

      modifier *= -1;
    }

    return res;
  }
}