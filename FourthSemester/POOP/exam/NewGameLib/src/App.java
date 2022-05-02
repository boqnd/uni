import game.EuchreGame;

public class App {
    public static void main(String[] args) throws Exception {
        EuchreGame game = new EuchreGame();

        game.dealHand();
        game.printHand();
        System.out.println(game.countHandStrength());
        System.out.println(game.hasJackANDAceTrump());
    }
}
