import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileWriterReader {

    public void fileOperation() {

        try {

            FileWriter writer = new FileWriter("student.txt");

            writer.write("Name : Ridy\n");
            writer.write("Department : CSE\n");
            writer.write("University : DIU");

            writer.close();

            System.out.println("Data Written Successfully.\n");

            FileReader reader = new FileReader("student.txt");

            int ch;

            System.out.println("File Content:");

            while ((ch = reader.read()) != -1) {

                System.out.print((char) ch);

            }

            reader.close();

        }

        catch (IOException e) {

            System.out.println("Error : " + e.getMessage());

        }

    }

    public static void main(String[] args) {

        FileWriterReader obj = new FileWriterReader();
        obj.fileOperation();

    }
}
