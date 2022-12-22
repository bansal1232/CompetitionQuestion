import model.InputCsvData;
import model.OutCsvData;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


class Solution {
    public static String getUniqueId(String... values) {
        if(values.length == 0) return "";

        StringBuilder stringBuilder = new StringBuilder(values[0]);
        for (String val :values) {
            stringBuilder.append("_").append(val);
        }
        return stringBuilder.toString();
    }
    public static Map<String, Float> getCommissionIdMap(List<InputCsvData> csvDataList) {
        Map<String, Float> commissionMap = new HashMap<>();
        for (InputCsvData csvData : csvDataList) {
            String keyId = getUniqueId(String.valueOf(csvData.getId()),csvData.getCarMake(), csvData.getCarModel());
            commissionMap.put(keyId, csvData.getCommission());
        }
        return commissionMap;
    }

    public static List<InputCsvData> parseCsvString(String csvString) {

        List<InputCsvData> csvDataValues = new ArrayList<>();

        String[] csvLines = csvString.split("\n");
        for(String line: csvLines) {
            // now parse on basis of ","
            String[] csvRow = line.split(",");

            InputCsvData csvData = new InputCsvData();
            csvData.setId(Long.parseLong(csvRow[0]));
            csvData.setCarMake(csvRow[1]);
            csvData.setCarModel(csvRow[2]);
            csvData.setCommission(Float.valueOf(csvRow[3]));
            csvDataValues.add(csvData);
        }
        return csvDataValues;
    }

    public static List<OutCsvData> reconcile(String expectedCommission, String actualCommision) {

        List<InputCsvData> expectedCommissionData = parseCsvString(expectedCommission);
        Map<String, Float> expectedCommissionIdMap = getCommissionIdMap(expectedCommissionData);

        List<InputCsvData> actualCommissionDataList = parseCsvString(actualCommision);

        List<OutCsvData> outCsvDataList = new ArrayList<>();

        for (InputCsvData actualCommissionData : actualCommissionDataList) {
            String actualCommissionId = getUniqueId(String.valueOf(actualCommissionData.getId()),
                    actualCommissionData.getCarMake(),
                    actualCommissionData.getCarModel());

            OutCsvData outCsvData = new OutCsvData();
            if (expectedCommissionIdMap.get(actualCommissionId) != null) {
                float expectedCommissionValue = expectedCommissionIdMap.get(actualCommissionId);
                if (expectedCommissionValue > actualCommissionData.getCommission()) {
                    outCsvData.setResult("UNDERPAID");
                }
                else if (expectedCommissionValue < actualCommissionData.getCommission()) {
                    outCsvData.setResult("OVERPAID");
                }
                else {
                    outCsvData.setResult("VALUE_MATCHED");
                }
                outCsvData.setExpectedCommission(expectedCommissionValue);
                outCsvData.setActualCommission(actualCommissionData.getCommission());

                expectedCommissionIdMap.remove(actualCommissionId);

            }
            else {
                outCsvData.setResult("UNEXPECTED_PAYMENT_RECEIVED");
                outCsvData.setExpectedCommission((float) 0);
                outCsvData.setActualCommission(actualCommissionData.getCommission());
            }

            outCsvData.setId(actualCommissionData.getId());
            outCsvData.setCarMake(actualCommissionData.getCarMake());
            outCsvData.setCarModel(actualCommissionData.getCarModel());
            outCsvDataList.add(outCsvData);
        }
        for (InputCsvData expectedCommissionRow: expectedCommissionData) {
            String id = getUniqueId(String.valueOf(expectedCommissionRow.getId()),
                    expectedCommissionRow.getCarMake(),
                    expectedCommissionRow.getCarModel());
            
            if (expectedCommissionIdMap.get(id) != null) {
                OutCsvData outCsvData = new OutCsvData();
                outCsvData.setId(expectedCommissionRow.getId());
                outCsvData.setCarMake(expectedCommissionRow.getCarMake());
                outCsvData.setCarModel(expectedCommissionRow.getCarModel());
                outCsvData.setExpectedCommission(expectedCommissionRow.getCommission());
                outCsvData.setActualCommission((float) 0);
                outCsvData.setResult("NO_PAYMENT_RECEIVED");
                outCsvDataList.add(outCsvData);
            }
        }

        return outCsvDataList;

    }

    public static void main(String[] args) {
        String expected = "001,Toyota,Altis,300.00\n" +
                "002,Honda,Civic,150.00\n" +
                "003,Toyota,Fortuner,180.00\n" +
                "004,BMW,Z4,850.00";

        String actual = "001,Toyota,Altis,300.00\n" +
                "001,Honda,City,0.00\n" +
                "002,Honda,Civic,50.00\n" +
                "003,Toyota,Fortuner,200.00\n" +
                "005,Mitsubishi,Lancer,200.00";
        List<OutCsvData> outCsvData = reconcile(expected, actual);
        outCsvData.forEach(
                output -> System.out.printf("%s,%s,%s,%s,%s,%s\n", output.getId(),
                        output.getCarMake(),output.getCarModel(),
                        output.getExpectedCommission(), output.getActualCommission(),
                        output.getResult())
        );
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
005,Mitsubishi,Lancer,0.00,200.00,UNEXPECTED_PAYMENT_RECEIVED (if expected->false but actual true)



expected_commission:
ID,CAR_MAKE,CAR_MODEL,COMMISSION
001,Toyota,Altis,300.00
002,Honda,Civic,150.00
003,Toyota,Fortuner,180.00
004,BMW,Z4,850.00
*/