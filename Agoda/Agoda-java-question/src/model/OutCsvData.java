package model;

public class OutCsvData extends CarBaseEntity{

    private Float expectedCommission;
    private Float actualCommission;
    private String result;

    public Float getExpectedCommission() {
        return expectedCommission;
    }

    public void setExpectedCommission(Float expectedCommission) {
        this.expectedCommission = expectedCommission;
    }

    public Float getActualCommission() {
        return actualCommission;
    }

    public void setActualCommission(Float actualCommission) {
        this.actualCommission = actualCommission;
    }

    public String getResult() {
        return result;
    }

    public void setResult(String result) {
        this.result = result;
    }

}
