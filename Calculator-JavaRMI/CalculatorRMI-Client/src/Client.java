/*
 @Author Mihailescu Ionut Emanuel
 */

import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.rmi.Naming;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Client extends JFrame implements ActionListener {

    double d1 = 0.0, d2 = 0.0, memorie=0.0;
    JButton butoane[] = new JButton[26];
    JTextField text;
    Container con;
    int buton, i;
    String str, num = "";
    JPanel tp, bp;

    public Client() {

        setTitle("Calculator");
        tp = new JPanel();
        bp = new JPanel();
        text = new JTextField(20);
        text.setEditable(false);
        con = getContentPane();
        bp.setLayout(new GridLayout(6, 3));
        tp.add(text);
        con.add(tp, "North");//pun textfield sus,in nord

        for (int i = 0; i < 10; i++) {
            butoane[i] = new JButton("" + (i + 1) % 10);
        }
        butoane[9] = new JButton("0");
        butoane[10] = new JButton("+");
        butoane[11] = new JButton("-");
        butoane[12] = new JButton("*");
        butoane[13] = new JButton("/");
        butoane[14] = new JButton("x^y");
        butoane[15] = new JButton("x^(-1)");
        butoane[16] = new JButton("!");
        butoane[17] = new JButton("sqrt");
        butoane[18] = new JButton("Clear");
        butoane[19] = new JButton(".");
        butoane[20] = new JButton("=");
        butoane[21] = new JButton("Mem+");
        butoane[22] = new JButton("Mem-");
        butoane[23] = new JButton("MemStoc");
        butoane[24] = new JButton("Mem");
        butoane[25] = new JButton("MemClear");

        for (int i = 0; i < 26; i++) {
            butoane[i].addActionListener(this);
            bp.add(butoane[i]);
        }
        con.add(bp, "Center");//centrez zona cu butoane in fereastra
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    }

    @Override
    public void actionPerformed(ActionEvent e) {

        str = e.getActionCommand();
        for (int i = 0; i < 10; i++) {
            if (e.getSource() == butoane[i]) { //tastele numerice
                num = num + str;
                text.setText(num);
            }
        }

        if ((e.getSource()) == butoane[19]) {//butoane[19]=virgula
            num = num + str;
            text.setText(num);
        }

        for (int i = 10; i < 18; i++) { //operatiile 
            if (e.getSource() == butoane[i]) {
                buton = i - 9;//stabilesc cazul
                if (num != "") {
                    text.setText("");//golesc zona de text
                    d1 = Double.parseDouble(num);
                    num = "";
                } else {
                    text.setText("");//se foloseste memoria si golesc zona de text
                }
            }
        }
        //Rezolv operatiile de aritate 1
        if(e.getSource()==butoane[15]){//inversarea
            text.setText("");
            num="";
            try{
                Calculator calc = (Calculator) Naming.lookup("//localhost:5555/RemoteCalculator");
                d1=calc.inv(d1);
                str = String.valueOf(d1);
                text.setText(str);
            }catch(Exception ex) {
                    text.setText("A aparut o eroare");
                }
        }
        if(e.getSource()==butoane[16]){//factorial
            text.setText("");
            num="";
            try{
                Calculator calc = (Calculator) Naming.lookup("//localhost:5555/RemoteCalculator");
                //System.out.print(d1);
                if(d1>0){
                d1=calc.fact((long)d1);
                str = String.valueOf(d1);
                text.setText(str);}
                else{
                    text.setText("Eroare de calcul");
                    d1=0.0;
                }
            }catch(Exception ex) {
                    text.setText("A aparut o eroare");
                }
        }
        if(e.getSource()==butoane[17]){//radical
            text.setText("");
            num="";
            try{
                Calculator calc = (Calculator) Naming.lookup("//localhost:5555/RemoteCalculator");
                if(d1>0)
                {d1=calc.sqrt(d1);
                str = String.valueOf(d1);
                text.setText(str);}
                else{
                    text.setText("Eroare de calcul");
                    d1=0.0;
                }
            }catch(Exception ex) {
                    text.setText("A aparut o eroare");
                }
        }
        //Operatiile dedicate memoriei 
        if(e.getSource()==butoane[21]){//Mem+
            memorie+=d1;
        }
        if(e.getSource()==butoane[22]){//Mem-
            memorie-=d1;
        }
        if(e.getSource()==butoane[23]){//MemStoc
            memorie=d1;
        }
        if(e.getSource()==butoane[24]){//Afisarea valorii din memorie
            str=String.valueOf(memorie);
            text.setText("");
            text.setText(str);
            d1=memorie;
        }
        if(e.getSource()==butoane[25]){//MemClear
            memorie=0.0;
        }
        if (e.getSource() == butoane[20]) {//butoane[20]=egalul
            if (!(text.getText().equals(""))) {
                text.setText("");
                d2 = Double.parseDouble(num);
                num = "";
                try {
                    Calculator calc = (Calculator) Naming.lookup("//localhost:5555/RemoteCalculator");
                    switch (buton) {
                        case 1:
                            d1 = calc.add(d1, d2);
                            break;
                        case 2:
                            d1 = calc.sub(d1, d2);
                            break;
                        case 3:
                            d1 = calc.mul(d1, d2);
                            break;
                        case 4:
                            d1 = calc.div(d1, d2);
                            break;
                        case 5:
                            d1 = calc.pow(d1, d2);
                            break;
                        default:
                            d1 = 0.0;
                    }
                    str = String.valueOf(d1);//transform rezultatul in string si il afisez
                    text.setText(str);
                } catch (Exception ex) {
                    text.setText("A aparut o eroare");
                }
            }
        }
        if (e.getSource() == butoane[18]) {//butoane[18]=Clear
            text.setText("");
            num = "";
            buton = 0;
        }
    }

    public static void main(String[] args) {

        JFrame fereastra = new Client();
        fereastra.setSize(500, 400);
        fereastra.setVisible(true);
    }
}
