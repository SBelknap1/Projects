import java.util.ArrayList;
import java.util.Scanner;

class Pet {
    String name;
    String type; // Dog or Cat
    String ownerName;
    String specialRequest;

    public Pet(String name, String type, String ownerName, String specialRequest) {
        this.name = name;
        this.type = type;
        this.ownerName = ownerName;
        this.specialRequest = specialRequest;
    }

    @Override
    public String toString() {
        return "Pet Name: " + name + ", Type: " + type + ", Owner: " + ownerName +
                (specialRequest.isEmpty() ? "" : ", Special Request: " + specialRequest);
    }
}

class BoardingSpace {
    int spaceNumber;
    boolean isOccupied;

    public BoardingSpace(int spaceNumber) {
        this.spaceNumber = spaceNumber;
        this.isOccupied = false;
    }
}

public class PetBoardingManagementSystem {
    static ArrayList<Pet> pets = new ArrayList<>();
    static ArrayList<BoardingSpace> spaces = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize boarding spaces
        for (int i = 1; i <= 10; i++) {
            spaces.add(new BoardingSpace(i)); // 10 spaces for simplicity
        }

        int choice;
        do {
            System.out.println("\nPet Boarding Management System Menu:");
            System.out.println("1. Check In Pet");
            System.out.println("2. View All Pets");
            System.out.println("3. View Available Spaces");
            System.out.println("4. Check Out Pet");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    checkInPet(scanner);
                    break;
                case 2:
                    viewAllPets();
                    break;
                case 3:
                    viewAvailableSpaces();
                    break;
                case 4:
                    checkOutPet(scanner);
                    break;
                case 0:
                    System.out.println("Exiting the system...");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        } while (choice != 0);
    }

    private static void checkInPet(Scanner scanner) {
        System.out.print("Enter pet's name: ");
        String name = scanner.nextLine();
        System.out.print("Enter pet's type (Dog or Cat): ");
        String type = scanner.nextLine();
        System.out.print("Enter owner's name: ");
        String ownerName = scanner.nextLine();
        System.out.print("Any special requests (leave blank if none): ");
        String specialRequest = scanner.nextLine();

        for (BoardingSpace space : spaces) {
            if (!space.isOccupied) {
                space.isOccupied = true;
                pets.add(new Pet(name, type, ownerName, specialRequest));
                System.out.println("Pet checked in successfully! Assigned Space #: " + space.spaceNumber);
                return;
            }
        }
        System.out.println("No available spaces! Please try again later.");
    }

    private static void viewAllPets() {
        if (pets.isEmpty()) {
            System.out.println("No pets are currently boarded.");
        } else {
            System.out.println("\nList of All Pets:");
            for (Pet pet : pets) {
                System.out.println(pet);
            }
        }
    }

    private static void viewAvailableSpaces() {
        System.out.println("\nAvailable Boarding Spaces:");
        for (BoardingSpace space : spaces) {
            if (!space.isOccupied) {
                System.out.println("Space #: " + space.spaceNumber);
            }
        }
    }

    private static void checkOutPet(Scanner scanner) {
        System.out.print("Enter pet's name to check out: ");
        String petName = scanner.nextLine();

        for (int i = 0; i < pets.size(); i++) {
            if (pets.get(i).name.equalsIgnoreCase(petName)) {
                pets.remove(i);
                spaces.get(i).isOccupied = false;
                System.out.println("Pet checked out successfully!");
                return;
            }
        }
        System.out.println("Pet not found! Please check the name and try again.");
    }
}
