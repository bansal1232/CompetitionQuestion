import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class paypal {
    // Object can be String, Integer, Boolean, List<Object> or Map<String, Object>

    public static String addDoubleQuotesToString(String val) {
        return "\"" + val + "\"";
    }

    public static String pasrseObjectMap(Object key) {

        StringBuilder json = new StringBuilder("");

        if (key instanceof String) {
            return addDoubleQuotesToString((String) key);
        } else if (key instanceof List) {
            json.append("[");
            for (Object keyObj : (List<Object>) key) {
                json.append(pasrseObjectMap(keyObj)).append(",");
            }
            if (((List<?>) key).size() > 0)
                json.setLength(json.length() - 1);
            json.append("]");
            return json.toString();

        } else if (key instanceof Integer) {
            return key.toString();
        } else if (key instanceof Boolean) {
            return key.toString();
        } else if (key instanceof Map) {
            json.append("{");
            for (Map.Entry<String, Object> obj : ((Map<String, Object>) key).entrySet()) {

                json.append(addDoubleQuotesToString(obj.getKey())).append(":").append(pasrseObjectMap(obj.getValue())).append(",");
            }
            json.setLength(json.length() - 1);
            json.append("}");
        }
        else if(key instanceof Address) {
            // todo: TO be complete
        }
        return json.toString();

    }

    public static String convertJsonToString(Map<String, Object> map) {
        return pasrseObjectMap(map);
    }

    public static void main(String[] args) {
        Map<String, Object> map = new HashMap<>();
        map.put("name", "abc");
        map.put("age", 25);
        map.put("hobbies", Arrays.asList("run", "swim", "drive"));

        Address address = new Address();
        address.setZip(Integer.parseInt("560099"));
        address.setCity("Bangalore");
        address.setState("Karnataka");
        map.put("address", address);

        map.put("active", true);

        String str = convertJsonToString(map);

        System.out.println(str);
    }
}


class Address {
    private String city;
    private Integer zip;
    private String state;
    public String getCity() {
        return city;
    }
    public void setCity(String city) {
        this.city = city;
    }

    public Integer getZip() {
        return zip;
    }

    public void setZip(Integer zip) {
        this.zip = zip;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }
}

