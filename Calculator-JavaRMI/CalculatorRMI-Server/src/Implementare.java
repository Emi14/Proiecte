/*
 @Author Mihailescu Ionut Emanuel
 */

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Implementare extends UnicastRemoteObject implements Calculator {

    public Implementare() throws RemoteException {
        super();
    }

    @Override
    public double add(double a, double b) throws RemoteException {
        return a + b;
    }

    @Override
    public double sub(double a, double b) throws RemoteException {
        return a - b;
    }

    @Override
    public double mul(double a, double b) throws RemoteException {
        return a * b;
    }

    @Override
    public double div(double a, double b) throws RemoteException {
        return a / b;
    }

    @Override
    public double pow(double a, double b) throws RemoteException {
        return Math.pow(a, b);
    }

    @Override
    public double inv(double a) throws RemoteException {
        return 1/a;
    }

    @Override
    public long fact(long a) throws RemoteException {
        long sol = 1;
        for (int i = 2; i <= a; i++) {
            sol *= i;
        }
        return sol;
    }

    @Override
    public double sqrt(double a) throws RemoteException {
        return Math.sqrt(a);
    }

}