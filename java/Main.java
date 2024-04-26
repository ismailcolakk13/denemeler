import java.util.*;

public class Main{//Does not work with turkish characters!!
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter any string");
        String input = scanner.nextLine();
        int[] count = new int[256]; 
        
        
        for (int i = 0; i < input.length(); i++) {
            char c= input.charAt(i);
            if(c!= ' '){
                count[c]++;
            }
        }
        
        char uniqueChar = ' ';
        for (int i = 0; i < input.length(); i++) {
            char c =input.charAt(i);
            if (count[c] == 1 && c!=' ') {
                uniqueChar = c;
                break;
            }
        }
        
        System.out.println("Tekrar etmeyen harf: " + uniqueChar);
        scanner.close();
    }

    
} 