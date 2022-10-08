package bio.data;

public enum AnimalType {
    BIRD("Птица"),
    MAMMAL("Бозайник"),
    REPTILE ("Влечуго"),
    FISH("Риба");
    private String typeName;

    AnimalType(String typeName) {
        this.typeName = typeName;
    }

    public String getTypeName() {
        return typeName;
    }
}


