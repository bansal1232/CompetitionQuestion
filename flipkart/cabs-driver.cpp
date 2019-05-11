#include<bits/stdc++.h>
using namespace std;

unordered_map < string, vector < int >> driver_name_ratings_map, customer_name_ratings_map;
unordered_map < string, vector < pair < string, int >>> customer_meta_data;
unordered_map<vector<int>, string>pp;
unordered_map < string, float > avg_customer_rating_map, avg_driver_rating_map;
unordered_map < string, bool > driver_offline_info;

/**
    Function to check for rating
    return false if rating lies beyond 1 to 5, otherwise true
**/
bool check_for_ratings(int rating) {
  return (rating < 1 || rating > 5) ? false : true;
}

void get_sample_input_data(int & total_persons) {

  string drivName, custName;
  int drivRating, custRating;

  for (int i = 0; i < total_persons; ++i) {
    cin >> drivName >> drivRating >> custName >> custRating;

    if (!check_for_ratings(drivRating) || !check_for_ratings(custRating)) {
      cerr << "Rating must lie between 1 to 5\n";
      exit(EXIT_FAILURE);
    }

    driver_name_ratings_map[drivName].push_back(drivRating);
    customer_name_ratings_map[custName].push_back(custRating);

    if(drivRating != 1 && custRating != 1)
        customer_meta_data[custName].push_back({drivName,drivRating});
  }
}

void calculate_average_rating_for_drivers(unordered_map < string, vector < int >> & driver_name_ratings_map) {
  for (auto & name: driver_name_ratings_map) {

    float ratings_sum = 0.0;

    for (auto const & ratings: driver_name_ratings_map[name.first]) {
      ratings_sum += ratings;
    }

    avg_driver_rating_map[name.first] = ratings_sum / driver_name_ratings_map[name.first].size();
  }

}
void calculate_average_rating_for_customers(unordered_map < string, vector < int >> & customer_name_ratings_map) {
  for (auto const & name: customer_name_ratings_map) {
    float sum = 0.0;
    for (auto const & ratings: customer_name_ratings_map[name.first]) {
      sum += ratings;
    }
    avg_customer_rating_map[name.first] = sum / customer_name_ratings_map[name.first].size();
  }

}

bool check_driver_availability(string name) {
   if(driver_offline_info.find(name) == driver_offline_info.end())
   {
       return true;
   }
   else return driver_offline_info[name];
}

void get_and_process_customers() {
  string cust_name;

  bool flag = false;
  cin >> cust_name;

  if (avg_customer_rating_map.find(cust_name) == avg_customer_rating_map.end()) {
    cerr << "Error! customer doesn't exist or has not taken any ride before";
    return;
  }

  float avg_customer_rating = avg_customer_rating_map[cust_name];
  cout << avg_customer_rating << endl;

  for (auto & driver_name: avg_driver_rating_map) {
    /**
        Check for driver availability
        return true (if available) other false
    **/
    if (!check_driver_availability(driver_name.first))
      continue;

    bool driver_flag = false;

    for(auto &cust_drive_name: customer_meta_data[cust_name])
    {
        if(cust_drive_name.first == driver_name.first){
            driver_flag = true;
            break;
        }

    }

    if(!driver_flag)
        continue;

    if (driver_name.second >= avg_customer_rating) {
      flag = true;
      cout << driver_name.first << " " << driver_name.second << endl;
    }
  }

  if (!flag) {
    bool last_driver_flag = false;
    for (auto & driver_name: customer_meta_data[cust_name]) {
      /**
          Check for driver availability
          return true (if available) other false;

          Check for driver rating
          Go forward if greater than 1 otherwise not
      **/
      if (check_driver_availability(driver_name.first) && driver_name.second > 1) {
        last_driver_flag = true;
        cout << driver_name.first << " " << avg_driver_rating_map[driver_name.first] << endl;
      }
    }
    if (!last_driver_flag) {
      cout << "Sorry, no driver found\n";
    }
  }
}

void get_driver_available_input() {
  int total_offline_drivers;
  string driver_name;
  bool flag;

  cin >> total_offline_drivers;

  for (int i = 0; i < total_offline_drivers; ++i) {
    cin >> driver_name >> flag;
    driver_offline_info[driver_name] = flag;
  }
}

int main() {
  freopen("in.c", "r", stdin);

  int total_persons;
  cin >> total_persons;

  get_sample_input_data(total_persons);

  calculate_average_rating_for_drivers(driver_name_ratings_map);
  calculate_average_rating_for_customers(customer_name_ratings_map);

  get_driver_available_input();

  int customer_query;
  cin >> customer_query;
  while(customer_query--)
    get_and_process_customers();
}
