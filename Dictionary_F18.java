/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dictionary_f18;

import com.sun.xml.internal.ws.util.StringUtils;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author esef2
 */
public class Dictionary_F18 {

    public static void main(String[] args) {

        HashMap<String, TripleSet> hash = new HashMap<>();

        TripleSet digIntoHash;

        int deepDigSize;
        int i = 0;
        int j = 0;

//        int arIndex[] = new int[10];
        System.out.println("! Loading data...");

        for (Enum enumKey : Enum.values()) {
            hash.put(enumKey.toString(), new TripleSet(enumKey.toString(), enumKey.getPartsOfSpeech(), enumKey.getDefiniton()));
        }
        System.out.println("! Loading completed...");

        System.out.println("----DICTIONARY 340 JAVA----");

        String userInput;
        Scanner sc = new Scanner(System.in);
        String inputSplit[] = new String[10];
        String keySearch;
//        do {
//            System.out.print("Search: ");
//
//            userInput = sc.nextLine();
//            inputSplit = userInput.split(" ");
//            int tokens = inputSplit.length;
//
//            switch (tokens) {
//                case 0:
//                    break;
//                case 1:
//                    keySearch = inputSplit[0];
//                    boolean check = hash.containsKey(keySearch.toUpperCase());
//                    if (check == true) {
//                        keySearch = keySearch.toUpperCase();
//                        digIntoHash = hash.get(keySearch);
//                        deepDigSize = digIntoHash.partOfSpeech.length;
//                        for (i = 0; i < deepDigSize; i++) {
//                            System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
//                        }
//                    }
//                    if (check == false) {
//                        keySearch = keySearch.toLowerCase();
//                        keySearch = StringUtils.capitalize(keySearch);
//                        check = hash.containsKey(keySearch);
//                        if (check == false) {
//                            System.out.println("<Not Found>");
//                        }
//                        if (check == true) {
//                            digIntoHash = hash.get(keySearch);
//                            deepDigSize = digIntoHash.partOfSpeech.length;
//                            for (i = 0; i < deepDigSize; i++) {
//                                System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
//                            }
//
//                        }
//
//                    }
//                    break;
//                case 2:
//                    keySearch = inputSplit[1];
//                    if (keySearch.equalsIgnoreCase("distinct")){
//                        
//                    } else {
//                        
//                        
//                    }
//                    
//                    break;
//                case 3:
//                    break;
//            }
//
//        } while (userInput.equalsIgnoreCase("!q") != true);

        do {
            digIntoHash = null;
            System.out.print("Search: ");

            userInput = sc.nextLine();

            System.out.println("|");
            inputSplit = userInput.split(" ");
            // check if user input is all lowercase 
            keySearch = inputSplit[0];
            boolean checkUpper = hash.containsKey(keySearch.toUpperCase());

            if (checkUpper == true) {
                keySearch = keySearch.toUpperCase();
                digIntoHash = hash.get(keySearch);
                deepDigSize = digIntoHash.partOfSpeech.length;

                if (inputSplit.length == 1) {
                    i = 0;
                    while (i < deepDigSize) {
                        System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
                        i++;

                    }
                    System.out.println("|");

                } else if (inputSplit.length > 2 && (inputSplit[2].equalsIgnoreCase("distinct") == true)) {
                    String fixed[] = removeDuplicates(digIntoHash.definition);
                    i = 0;

                    if (fixed.length == 1) {
                        while (digIntoHash.partOfSpeech[i].compareToIgnoreCase(inputSplit[1]) != 0) {
                            i++;
                        }
                        System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
                        System.out.println("|");
                    }
                    while (i < fixed.length) {
                        if (digIntoHash.partOfSpeech[i].compareToIgnoreCase(inputSplit[1]) != 0) {

                            i++;
                        } else {

                            System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], fixed[i]);
                            i++;
                        }
                    }
                    System.out.println("|");

                } // if keyword and part of speech entered
                else if (inputSplit.length > 1) {

                    if (inputSplit[1].equalsIgnoreCase("distinct")) {
                        String prefix[] = Arrays.copyOf(digIntoHash.partOfSpeech, digIntoHash.partOfSpeech.length);

                        String fixed[] = removeDuplicates(digIntoHash.partOfSpeech);
                        for (i = 0; i < fixed.length; i++) {
                            System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);

                        }
                        System.out.println("|");
                        digIntoHash.partOfSpeech = Arrays.copyOf(prefix, prefix.length);

                    }

                    if (!inputSplit[1].equalsIgnoreCase("distinct")) {
                        j = 0;
                        for (i = 0; i < deepDigSize; i++) {
                            if (digIntoHash.partOfSpeech[i].equalsIgnoreCase(inputSplit[1].toLowerCase()) == true) {
                                j++;

                                System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
                            }
                        }
//                        System.out.println("|");
                        if (j == 0) {
                            if (inputSplit[1].contains("verb") || inputSplit[1].contains("noun")
                                    || inputSplit[1].contains("adjective") || inputSplit[1].contains("adverb")
                                    || inputSplit[1].contains("conjunction") || inputSplit[1].contains("interjection")
                                    || inputSplit[1].contains("pronoun") || inputSplit[1].contains("preposition")) {
                                System.out.println("<Not found>");
                                System.out.println("|");

                            } else {
                                System.out.println("<2nd argument must be a part of speech or \"distinct\">");
                                j = 0;

                            }
                        }

                        System.out.println("|");

                    }
                }

            } else {

                // checks if user enters anything else in a strange case sensitive order
                keySearch = keySearch.toLowerCase();
                keySearch = StringUtils.capitalize(keySearch);
                if (hash.containsKey(keySearch) == false) {
                    if (keySearch.equalsIgnoreCase("!q")) {
                        System.out.println("-----THANK YOU-----");
                        return;
                    }
                    System.out.println("<Not Found>");
                    System.out.println("|");
                }

                if (hash.containsKey(keySearch) == true) {
                    digIntoHash = hash.get(keySearch);
                    deepDigSize = digIntoHash.partOfSpeech.length;

                    // if only keyword search
                    if (inputSplit.length == 1) {
                        i = 0;
                        while (i < deepDigSize) {
                            System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
                            i++;

                        }
                        System.out.println("|");

                    } else if (inputSplit.length > 2 && (inputSplit[2].equalsIgnoreCase("distinct") == true)) {

                        String fixed[] = removeDuplicates(digIntoHash.definition);
                        i = 0;

                        if (fixed.length == 1) {
                            while (digIntoHash.partOfSpeech[i].compareToIgnoreCase(inputSplit[1]) != 0) {
                                i++;
                            }
                            System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
//                            System.out.println("|");
                        }
                        while (i < fixed.length) {
                            if (digIntoHash.partOfSpeech[i].compareToIgnoreCase(inputSplit[1]) != 0) {

                                i++;
                            } else {

                                System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], fixed[i]);
                                i++;
                            }
                        }
                        System.out.println("|");

                    } // if keyword and part of speech entered
                    else if (inputSplit.length > 1) {

                        if (inputSplit[1].equalsIgnoreCase("distinct")) {
                            String prefix[] = Arrays.copyOf(digIntoHash.partOfSpeech, digIntoHash.partOfSpeech.length);

                            String fixed[] = removeDuplicates(digIntoHash.partOfSpeech);
                            for (i = 0; i < fixed.length; i++) {
                                System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);

                            }
                            System.out.println("|");
                            digIntoHash.partOfSpeech = Arrays.copyOf(prefix, prefix.length);

                        }

                        if (!inputSplit[1].equalsIgnoreCase("distinct")) {
                            j = 0;
                            for (i = 0; i < deepDigSize; i++) {
                                if (digIntoHash.partOfSpeech[i].equalsIgnoreCase(inputSplit[1].toLowerCase()) == true) {
                                    j++;
                                    System.out.printf("%s   [%s]   : %s\n", digIntoHash.keyword, digIntoHash.partOfSpeech[i], digIntoHash.definition[i]);
                                }
                            }
//                            System.out.println("|");
                            if (j == 0) {
                                if (inputSplit[1].contains("verb") || inputSplit[1].contains("noun")
                                        || inputSplit[1].contains("adjective") || inputSplit[1].contains("adverb")
                                        || inputSplit[1].contains("conjunction") || inputSplit[1].contains("interjection")
                                        || inputSplit[1].contains("pronoun") || inputSplit[1].contains("preposition")) {
                                    System.out.println("<Not found>");
//                                    System.out.println("|");

                                } else {
                                    System.out.println("<2nd argument must be a part of speech or \"distinct\">");
                                    j = 0;

                                }
                            }

                            System.out.println("|");
                        }
                    }

                }

            }
        } while (userInput.equalsIgnoreCase("!q") != true);
        System.out.println("-----THANK YOU-----");

    }

    String getKey(String one, String two, String three) {

        if (two == null) {

        }
        if (three == null) {

        }
        return "";
    }

    public static String[] removeDuplicates(String[] A) {
        if (A.length < 2) {
            return A;
        }

        int j = 0;
        int i = 1;

        while (i < A.length) {
            if (A[i] == A[j]) {
                i++;
            } else {
                j++;
                A[j] = A[i];
                i++;
            }
        }

        String[] B = Arrays.copyOf(A, j + 1);

        return B;
    }
}
