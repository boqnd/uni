package bio.data;

public class AnimalInstance {
    private int animalKey;
    private String animalName;
    private int animalAge;

    private static int counter = 0;

    private final String INSTANCE_ID;

    public String getINSTANCE_ID() {
        return INSTANCE_ID;
    }

    public int getAnimalKey() {
        return animalKey;
    }

    public String getAnimalName() {
        return animalName;
    }

    public int getAnimalAge() {
        return animalAge;
    }

    public void setAnimalKey(int animalKey) {
        this.animalKey = animalKey;
    }

    public void setAnimalName(String animalName) {
        if (animalName == null) {
            this.animalName = "animalName";
        } else {
            this.animalName = animalName;
        }
    }

    public void setAnimalAge(int animalAge) {
        if (animalAge < 0) {
            this.animalAge = 0;
        } else {
            this.animalAge = animalAge;
        }
    }

    public AnimalInstance(int animalKey, String animalName, int animalAge) {
        this.setAnimalKey(animalKey);
        this.setAnimalName(animalName);
        this.setAnimalAge(animalAge);
        this.INSTANCE_ID = String.format("%s %03d", this.animalName, counter++);
    }

    @Override
    public String toString() {
        return String.format("%s, възраст: %d", this.getINSTANCE_ID(), this.getAnimalAge());
    }
}
