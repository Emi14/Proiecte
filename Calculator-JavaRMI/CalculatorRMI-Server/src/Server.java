/*
@Author Mihailescu Ionut Emanuel
*/

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {

    public Server() {
    }

    public static void main(String args[]) {
        try {
            //Implementare im = new Implementare();
            System.out.println("Server starting...");
            Registry reg = LocateRegistry.createRegistry(5555);
            reg.rebind("RemoteCalculator", new Implementare());
            System.out.println("Server ready.");
        } catch (Exception e) {
            System.err.println(e);
            System.exit(1);
        }

    }
}