Can you re-write the same program in simpler form ?
public class Main {
    public static boolean checkForSymbol(char inputChar) {
        return !((inputChar >= 'a' && inputChar <= 'z')
                || (inputChar >= 'A' && inputChar <= 'Z'
                || inputChar >= '0' && inputChar <= '9'));
    }

    private static int getLastValidCharIndex(String encodedInput, int lastInd) {
        for (int i = lastInd; i >= 0; --i) {
            if (!checkForSymbol(encodedInput.charAt(i))) {
                return i;
            }
        }
        return -1;
    }

    public static String getDecodedOutput(String encodedInput) throws Exception {
        int len = encodedInput.length();
        StringBuilder decodedString = new StringBuilder();

        int lastInd = len - 1;
        for (int ind = 0; ind < len; ind++) {
            char currentChar = encodedInput.charAt(ind);
            if (checkForSymbol(currentChar)) {
                decodedString.append(currentChar);
            } else {
                int validCharIndex = getLastValidCharIndex(encodedInput, lastInd);
                if (validCharIndex != -1) {
                    decodedString.append(encodedInput.charAt(validCharIndex));
                } else {
                    throw new Exception("Not valid String");
                }
                lastInd = validCharIndex - 1;
            }
        }
        return decodedString.toString();
    }


    public static void main(String[] args) throws Exception {
        /*
        ATR$UP&G
         To
        GPU$RT&A
        * */
        String decodedString = getDecodedOutput("ATR$Ul9P&G");
        System.out.println(decodedString);
    }
}

/*
Q1. map vs flatMap in java stream

Q2. What is Immutable class in Java

 */
