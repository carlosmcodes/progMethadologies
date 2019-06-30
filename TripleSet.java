package dictionary_f18;

public class TripleSet {

    String keyword;
    String partOfSpeech[];
    String definition[];

    TripleSet(String kw, String pos[], String def[]) {
        this.keyword = kw;
        this.partOfSpeech = pos;
        this.definition = def;
    }

    String getKeyword() {
        return keyword;
    }

    String[] getPartOfSpeech(int i) {
        return partOfSpeech;
    }

    String[] getDefinition(int i) {
        return definition;
    }

}
