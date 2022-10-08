package bio.data;

import java.util.Arrays;

public class Animal {
    private String name;
    private AnimalType animalType;
    private boolean predator;
    private String region;
    private boolean endangered;

    public static final String[] REGIONS = {"Africa", "Asia", "Australia", "Europe", "America"};

    public String getName() {
        return name;
    }

    public AnimalType getAnimalType() {
        return animalType;
    }

    public boolean isPredator() {
        return predator;
    }

    public String getRegion() {
        return region;
    }

    public boolean isEndangered() {
        return endangered;
    }

    public void setName(String name) {
        if (name == null) {
            this.name = "defaultName";
        }else {
            this.name = name;
        }
    }

    public void setAnimalType(AnimalType animalType) {
        if (animalType == null) {
            this.animalType = AnimalType.BIRD;
        } else {
            this.animalType = animalType;
        }
    }

    public void setPredator(boolean predator) {
        this.predator = predator;
    }

    public void setRegion(String region) {
        if (Arrays.stream(REGIONS).anyMatch(r->r.equals(region))) {
            this.region = region;
        } else {
            this.region = "Unknown";
        }
    }

    public void setEndangered(boolean endangered) {
        this.endangered = endangered;
    }

    public Animal(String name, AnimalType animalType, boolean predator, String region, boolean endangered) {
        this.setName(name);
        this.setAnimalType(animalType);
        this.setPredator(predator);
        this.setRegion(region);
        this.setEndangered(endangered);
    }

    @Override
    public String toString() {
        return String.format("Животно{ %s, тип= %s, хищник= %s, район= %s, застрашен= %s}", this.getName(), this.getAnimalType(), this.isPredator(), this.getRegion(), this.isEndangered());
    }
}
