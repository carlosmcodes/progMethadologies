package dictionary_f18;

public enum Enum {

    Placeholder("Placeholder",
            new String[]{"adjective", "adjective", "adverb", "conjunction", "interjection", "noun", "noun", "noun",
                "preposition", "pronoun", "verb"},
            new String[]{"To be updated...", "To be updated...", "To be updated...", "To be updated...",
                "To be updated...", "To be updated...", "To be updated...", "To be updated...", "To be updated...",
                "To be updated...", "To be updated..."}),
    CSC340("CSC340", new String[]{"adjective", "noun", "noun", "noun"},
            new String[]{"= C++ version of CSC210 + CSC220 + more. ", "A CS upper division course",
                "Many hours outside of class.", "Programming Methodology"}),
    //Facebook("Facebook", new String[] { "test", "test2" }, new String[] {
    // "test3", "test4" }),
    CSC210("CSC210", new String[]{"adjective", "adjective", "noun", "verb"},
            new String[]{"Comfortable with Objects and Classes.", "Ready for CSC 220.", "Intro to Java.",
                "To learn Java."}),
    CSC220("CSC220", new String[]{"adjective", "noun", "verb"},
            new String[]{"Ready to create complex data structures.", "Data Structures.",
                "To create data structures."}),
    Book("Book", new String[]{"verb", "verb", "noun", "noun"},
            new String[]{"To arrange for someone to have a seat on a plane.",
                "To arrange something on a particular date.", "A set of pages.", "A written work published in printed or electronic form."}),
    Bookable("Bookable", new String[]{"adjective"}, new String[]{"Can be ordered in advance."}),
    Conjunction("Conjunction", new String[]{"noun"},
            new String[]{"Conjunction is a word that joins words, phrases or sentences, for example \r\n"
                + "\'and\', \'but\', \'or\'."}),
    Interjection("Interjection", new String[]{"noun"},
            new String[]{"Interjection is a short sound, word or phrase spoken suddenly to express \r\n"
                + "an emotion. Oh!, Look out! and Ow! are interjections."}),
    Pronoun("Pronoun", new String[]{"noun", "noun"}, new String[]{
        "The part of speech that substitutes for nouns or noun phrases and designates persons or things asked for, previously specified, or understood from the context.",
        "Any of the words within this part of speech, such as he or whom."}),
    Adjective("Adjective", new String[]{"noun"},
            new String[]{"Adjective is a word that describes a person or thing, for example big, red \r\n"
                + "and clever in a big house, red wine and a clever idea."}),
    Verb("Verb", new String[]{"noun",},
            new String[]{"Verb is a word or group of words that expresses an action (such as eat), an event \r\n"
                + "(such as happen) or a state (such as exist)."});

    public String keywords;
    public String[] partOfSpeech;
    public String[] Def;

    Enum(String keyword, String[] partOfSpeech, String[] definition) {
        this.keywords = keyword;
        this.partOfSpeech = partOfSpeech;
        this.Def = definition;
    }

    public String getkeyWord() {
        return keywords;
    }

    public String[] getPartsOfSpeech() {
        return partOfSpeech;
    }

    public String[] getDefiniton() {
        return Def;
    }

}
