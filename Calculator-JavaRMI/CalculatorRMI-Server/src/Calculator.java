/*
 @Author Mihailescu Ionut Emanuel
 */

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Calculator extends Remote {

    public double add(double a, double b) throws RemoteException;

    public double sub(double a, double b) throws RemoteException;

    public double mul(double a, double b) throws RemoteException;

    public double div(double a, double b) throws RemoteException;

    public double pow(double a, double b) throws RemoteException;

    public double inv(double a) throws RemoteException;

    public long fact(long a) throws RemoteException;

    public double sqrt(double a) throws RemoteException;

    public final static String LOOKUPNAME = "rmi://localhost/Calculator";
}
