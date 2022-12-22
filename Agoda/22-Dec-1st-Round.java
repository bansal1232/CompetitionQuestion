import java.io.*;
import java.util.*;

// Main class should be named 'Solution'
class CsvData {
    Long Id;
    String carMake;
    String carModel;
    Double commisison;


    public Long getId() {
        return Id;
    }

    public void setId(Long id) {
        Id = id;
    }

    public String getCarMake() {
        return carMake;
    }

    public void setCarMake(String carMake) {
        this.carMake = carMake;
    }

    public String getCarModel() {
        return carModel;
    }

    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    public Double getCommisison() {
        return commisison;
    }

    public void setCommisison(Double commisison) {
        this.commisison = commisison;
    }
}
// ID,CAR_MAKE,CAR_MODEL,EXPECTED_COMMISSION,ACTUAL_COMMISSION,RESULT

class Solution {
    public static List<CsvData> parseCsvString(String csvString, Map<String, CsvData>carType) {

        List<CsvData> csvDataValues = new ArrayList<>();

        String[] csvLines = csvString.split("\n");
        for(String line: csvLines) {
            // now parse on basis of ","
            String[] csvRow = line.split(",");

            CsvData csvData = new CsvData();
            csvData.setId(Long.parseLong(csvRow[0]));
            csvData.setCarMake(csvRow[1]);
            csvData.setCarModel(csvRow[2]);
            csvData.setCommisison(Double.parseDouble(csvRow[3]));

            String id = csvData.getId() + csvData.getCarMake() + csv.getCarModel();
            carType.put(id, csvData);
            csvDataValues.add(csvData);
        }
        return csvDataValues;
    }

    public static String reconcile(String expectedCommision, String actualCommision) {
        Map<String, CsvData> expectedCarId = new HashMap<>();
        Map<String, CsvData> actualCarId = new HashMap<>();

        List<CsvData> expectedCommisionData = parseCsvString(expectedCommision, expectedCarId);
        List<CsvData> actualCommisionData = parseCsvString(expectedCommision, actualCarId);

        actualCommisionData.forEach(actualCsvData -> {
            String id = getCarId(actualCsvData);
            CsvData expectedCsvData = expectedCarId.get(id);
            actualCsvData.

        });


        return "";

    }

    public static void main(String[] args) {
        System.out.println("Hello, World");
    }
}


/*
Design and code reconcile() method that takes expected and actual commission string data (in csv format) and reconciles these as:

EXPECTED COMMISSION = ACTUAL COMMISSION -> VALUE_MATCHED
EXPECTED COMMISSION > ACTUAL COMMISSION -> UNDERPAID
EXPECTED COMMISSION < ACTUAL COMMISSION -> OVERPAID
ACTUAL COMMISSION NOT RECEIVED          -> NO_PAYMENT_RECEIVED
UNEXPECTED COMMISSION RECEIVED          -> UNEXPECTED_PAYMENT_RECEIVED

Notes:
Actual Commission ID can be reused by different CAR MAKE

Example:

expected_commission:
ID,CAR_MAKE,CAR_MODEL,COMMISSION
001,Toyota,Altis,300.00
002,Honda,Civic,150.00
003,Toyota,Fortuner,180.00
004,BMW,Z4,850.00


actual_commission:
ID,CAR_MAKE,CAR_MODEL,COMMISSION
001,Toyota,Altis,300.00
001,Honda,City,0.00
002,Honda,Civic,50.00
003,Toyota,Fortuner,200.00
005,Mitsubishi,Lancer,200.00



Expected Result:
ID,CAR_MAKE,CAR_MODEL,EXPECTED_COMMISSION,ACTUAL_COMMISSION,RESULT
001,Toyota,Altis,300.00,300.00,VALUE_MATCHED
002,Honda,Civic,150.00,50.00,UNDERPAID
003,Toyota,Fortuner,180.00,200.00,OVERPAID
004,BMW,Z4,850.00,0.00,NO_PAYMENT_RECEIVED
005,Mitsubishi,Lancer,0.00,200.00,UNEXPECTED_PAYMENT_RECEIVED
*/



/*
expected_commission:
ID,CAR_MAKE,CAR_MODEL,COMMISSION
001,Toyota,Altis,300.00
002,Honda,Civic,150.00
003,Toyota,Fortuner,180.00
004,BMW,Z4,850.00

class Car {
    Integer Id;
    String carMake;
}

List<List<
string[] commaStr =  str.parse("\n")
string[] finalStr =  commaStr,split(",")

if acual commission is 0 , no consider
*/
