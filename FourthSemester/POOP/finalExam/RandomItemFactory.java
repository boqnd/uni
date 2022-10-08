import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.Function;
import java.util.function.Supplier;

public interface RandomItemFactory  extends Function<Integer,String>, Supplier<List<Item>> {

  Random GENERATOR = new Random();
  int BARCODE_SIZE = 5;

  default String apply(Integer num){
    String b = "";
    for (int i = 0; i < num; i++) {
        int s = GENERATOR.nextInt(0,2);
        if(s == 0) {
            b += ":";
        }
        else if(s == 1) {
            b += "|";
        }
    }
    return b;
  }

  private void setRandomData(List<Item> items, int count)  {
    for (int i = 0; i < count; i++) {
      Item it = new Item();
      it.setBARCODE(apply(BARCODE_SIZE));
      it.setPrice(GENERATOR.nextInt(19,30));
      it.setQuantity(GENERATOR.nextInt(0,10));
      items.add(it);
    }
  }

  default List<Item> get() {
    List<Item> items = new ArrayList<Item>();
    int c = GENERATOR.nextInt(0, 6);

    setRandomData(items, c);

    return items;
  }
}