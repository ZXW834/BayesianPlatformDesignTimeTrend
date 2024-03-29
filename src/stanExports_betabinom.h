// Generated by rstantools.  Do not edit by hand.

/*
    BayesianPlatformDesignTimeTrend is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BayesianPlatformDesignTimeTrend is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BayesianPlatformDesignTimeTrend.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#ifndef USE_STANC3
#define USE_STANC3
#endif
#include <rstan/rstaninc.hpp>
// Code generated by stanc v2.26.1-4-gd72b68b7-dirty
#include <stan/model/model_header.hpp>
namespace model_betabinom_namespace {
inline void validate_positive_index(const char* var_name, const char* expr,
                                    int val) {
  if (val < 1) {
    std::stringstream msg;
    msg << "Found dimension size less than one in simplex declaration"
        << "; variable=" << var_name << "; dimension size expression=" << expr
        << "; expression value=" << val;
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}
inline void validate_unit_vector_index(const char* var_name, const char* expr,
                                       int val) {
  if (val <= 1) {
    std::stringstream msg;
    if (val == 1) {
      msg << "Found dimension size one in unit vector declaration."
          << " One-dimensional unit vector is discrete"
          << " but the target distribution must be continuous."
          << " variable=" << var_name << "; dimension size expression=" << expr;
    } else {
      msg << "Found dimension size less than one in unit vector declaration"
          << "; variable=" << var_name << "; dimension size expression=" << expr
          << "; expression value=" << val;
    }
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using std::pow;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::model_base_crtp;
using stan::model::rvalue;
using stan::model::cons_list;
using stan::model::index_uni;
using stan::model::index_max;
using stan::model::index_min;
using stan::model::index_min_max;
using stan::model::index_multi;
using stan::model::index_omni;
using stan::model::nil_index_list;
using namespace stan::math;
using stan::math::pow; 
stan::math::profile_map profiles__;
static int current_statement__= 0;
static const std::vector<string> locations_array__ = {" (found before start of program)",
                                                      " (in 'betabinom', line 10, column 2 to column 36)",
                                                      " (in 'betabinom', line 19, column 2 to column 30)",
                                                      " (in 'betabinom', line 22, column 4 to column 32)",
                                                      " (in 'betabinom', line 25, column 6 to column 50)",
                                                      " (in 'betabinom', line 23, column 21 to line 26, column 5)",
                                                      " (in 'betabinom', line 23, column 4 to line 26, column 5)",
                                                      " (in 'betabinom', line 27, column 4 to column 46)",
                                                      " (in 'betabinom', line 21, column 2 to line 28, column 3)",
                                                      " (in 'betabinom', line 13, column 2 to column 44)",
                                                      " (in 'betabinom', line 14, column 2 to column 26)",
                                                      " (in 'betabinom', line 2, column 2 to column 17)",
                                                      " (in 'betabinom', line 3, column 2 to column 17)",
                                                      " (in 'betabinom', line 4, column 8 to column 9)",
                                                      " (in 'betabinom', line 4, column 2 to column 35)",
                                                      " (in 'betabinom', line 5, column 8 to column 9)",
                                                      " (in 'betabinom', line 5, column 2 to column 35)",
                                                      " (in 'betabinom', line 6, column 2 to column 24)",
                                                      " (in 'betabinom', line 7, column 2 to column 21)",
                                                      " (in 'betabinom', line 10, column 27 to column 28)",
                                                      " (in 'betabinom', line 19, column 10 to column 11)"};
#include <stan_meta_header.hpp>
class model_betabinom final : public model_base_crtp<model_betabinom> {
private:
  int K;
  int N;
  std::vector<int> z;
  std::vector<int> y;
  double pistar;
  int pess;
 
public:
  ~model_betabinom() { }
  
  inline std::string model_name() const final { return "model_betabinom"; }
  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.26.1-4-gd72b68b7-dirty", "stancflags = "};
  }
  
  
  model_betabinom(stan::io::var_context& context__,
                  unsigned int random_seed__ = 0,
                  std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static const char* function__ = "model_betabinom_namespace::model_betabinom";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      current_statement__ = 11;
      context__.validate_dims("data initialization","K","int",
          context__.to_vec());
      K = std::numeric_limits<int>::min();
      
      current_statement__ = 11;
      K = context__.vals_i("K")[(1 - 1)];
      current_statement__ = 11;
      current_statement__ = 11;
      check_greater_or_equal(function__, "K", K, 1);
      current_statement__ = 12;
      context__.validate_dims("data initialization","N","int",
          context__.to_vec());
      N = std::numeric_limits<int>::min();
      
      current_statement__ = 12;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 12;
      current_statement__ = 12;
      check_greater_or_equal(function__, "N", N, 0);
      current_statement__ = 13;
      validate_non_negative_index("z", "N", N);
      current_statement__ = 14;
      context__.validate_dims("data initialization","z","int",
          context__.to_vec(N));
      z = std::vector<int>(N, std::numeric_limits<int>::min());
      
      current_statement__ = 14;
      assign(z, nil_index_list(), context__.vals_i("z"),
        "assigning variable z");
      current_statement__ = 14;
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        current_statement__ = 14;
        current_statement__ = 14;
        check_greater_or_equal(function__, "z[sym1__]", z[(sym1__ - 1)], 1);}
      current_statement__ = 14;
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        current_statement__ = 14;
        current_statement__ = 14;
        check_less_or_equal(function__, "z[sym1__]", z[(sym1__ - 1)], K);}
      current_statement__ = 15;
      validate_non_negative_index("y", "N", N);
      current_statement__ = 16;
      context__.validate_dims("data initialization","y","int",
          context__.to_vec(N));
      y = std::vector<int>(N, std::numeric_limits<int>::min());
      
      current_statement__ = 16;
      assign(y, nil_index_list(), context__.vals_i("y"),
        "assigning variable y");
      current_statement__ = 16;
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        current_statement__ = 16;
        current_statement__ = 16;
        check_greater_or_equal(function__, "y[sym1__]", y[(sym1__ - 1)], 0);}
      current_statement__ = 16;
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        current_statement__ = 16;
        current_statement__ = 16;
        check_less_or_equal(function__, "y[sym1__]", y[(sym1__ - 1)], 1);}
      current_statement__ = 17;
      context__.validate_dims("data initialization","pistar","double",
          context__.to_vec());
      pistar = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 17;
      pistar = context__.vals_r("pistar")[(1 - 1)];
      current_statement__ = 17;
      current_statement__ = 17;
      check_greater_or_equal(function__, "pistar", pistar, 0);
      current_statement__ = 18;
      context__.validate_dims("data initialization","pess","int",
          context__.to_vec());
      pess = std::numeric_limits<int>::min();
      
      current_statement__ = 18;
      pess = context__.vals_i("pess")[(1 - 1)];
      current_statement__ = 18;
      current_statement__ = 18;
      check_greater_or_equal(function__, "pess", pess, 0);
      current_statement__ = 19;
      validate_non_negative_index("theta", "K", K);
      current_statement__ = 20;
      validate_non_negative_index("times_to_be_best", "K", K);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    num_params_r__ = 0U;
    
    try {
      num_params_r__ += K;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
  }
  template <bool propto__, bool jacobian__, typename VecR, typename VecI, stan::require_vector_like_t<VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    static const char* function__ = "model_betabinom_namespace::log_prob";
(void) function__;  // suppress unused var warning
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      Eigen::Matrix<local_scalar_t__, -1, 1> theta;
      theta = Eigen::Matrix<local_scalar_t__, -1, 1>(K);
      stan::math::fill(theta, DUMMY_VAR__);
      
      current_statement__ = 1;
      theta = in__.vector(K);
      current_statement__ = 1;
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        current_statement__ = 1;
        if (jacobian__) {
          current_statement__ = 1;
          assign(theta, cons_list(index_uni(sym1__), nil_index_list()),
            stan::math::lub_constrain(theta[(sym1__ - 1)], 0, 1, lp__),
            "assigning variable theta");
        } else {
          current_statement__ = 1;
          assign(theta, cons_list(index_uni(sym1__), nil_index_list()),
            stan::math::lub_constrain(theta[(sym1__ - 1)], 0, 1),
            "assigning variable theta");
        }}
      {
        current_statement__ = 9;
        lp_accum__.add(
          beta_lpdf<propto__>(theta, (pess * pistar), (pess * (1 - pistar))));
        current_statement__ = 10;
        lp_accum__.add(
          bernoulli_lpmf<propto__>(y,
            rvalue(theta, cons_list(index_multi(z), nil_index_list()),
              "theta")));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr>
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.resize(0);
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    static const char* function__ = "model_betabinom_namespace::write_array";
(void) function__;  // suppress unused var warning
    (void) function__;  // suppress unused var warning
    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      Eigen::Matrix<double, -1, 1> theta;
      theta = Eigen::Matrix<double, -1, 1>(K);
      stan::math::fill(theta, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 1;
      theta = in__.vector(K);
      current_statement__ = 1;
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        current_statement__ = 1;
        assign(theta, cons_list(index_uni(sym1__), nil_index_list()),
          stan::math::lub_constrain(theta[(sym1__ - 1)], 0, 1),
          "assigning variable theta");}
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        vars__.emplace_back(theta[(sym1__ - 1)]);}
      if (logical_negation((primitive_value(emit_transformed_parameters__) ||
            primitive_value(emit_generated_quantities__)))) {
        return ;
      } 
      if (logical_negation(emit_generated_quantities__)) {
        return ;
      } 
      Eigen::Matrix<double, -1, 1> times_to_be_best;
      times_to_be_best = Eigen::Matrix<double, -1, 1>(K);
      stan::math::fill(times_to_be_best, std::numeric_limits<double>::quiet_NaN());
      
      {
        double best_prob;
        best_prob = std::numeric_limits<double>::quiet_NaN();
        
        current_statement__ = 3;
        best_prob = max(theta);
        current_statement__ = 6;
        for (int k = 1; k <= K; ++k) {
          current_statement__ = 4;
          assign(times_to_be_best, cons_list(index_uni(k), nil_index_list()),
            logical_gte(theta[(k - 1)], best_prob),
            "assigning variable times_to_be_best");}
        current_statement__ = 7;
        assign(times_to_be_best, nil_index_list(),
          divide(stan::model::deep_copy(times_to_be_best),
            sum(times_to_be_best)), "assigning variable times_to_be_best");
      }
      current_statement__ = 2;
      current_statement__ = 2;
      check_simplex(function__, "times_to_be_best", times_to_be_best);
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        vars__.emplace_back(times_to_be_best[(sym1__ - 1)]);}
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, stan::require_std_vector_t<VecVar>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline void transform_inits_impl(const stan::io::var_context& context__,
                                   VecI& params_i__, VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.clear();
    vars__.reserve(num_params_r__);
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      Eigen::Matrix<double, -1, 1> theta;
      theta = Eigen::Matrix<double, -1, 1>(K);
      stan::math::fill(theta, std::numeric_limits<double>::quiet_NaN());
      
      {
        std::vector<local_scalar_t__> theta_flat__;
        current_statement__ = 1;
        assign(theta_flat__, nil_index_list(), context__.vals_r("theta"),
          "assigning variable theta_flat__");
        current_statement__ = 1;
        pos__ = 1;
        current_statement__ = 1;
        for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
          current_statement__ = 1;
          assign(theta, cons_list(index_uni(sym1__), nil_index_list()),
            theta_flat__[(pos__ - 1)], "assigning variable theta");
          current_statement__ = 1;
          pos__ = (pos__ + 1);}
      }
      Eigen::Matrix<double, -1, 1> theta_free__;
      theta_free__ = Eigen::Matrix<double, -1, 1>(K);
      stan::math::fill(theta_free__, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 1;
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        current_statement__ = 1;
        assign(theta_free__, cons_list(index_uni(sym1__), nil_index_list()),
          stan::math::lub_free(theta[(sym1__ - 1)], 0, 1),
          "assigning variable theta_free__");}
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        vars__.emplace_back(theta_free__[(sym1__ - 1)]);}
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__.clear();
    names__.emplace_back("theta");
    names__.emplace_back("times_to_be_best");
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    dimss__.clear();
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(K)});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(K)});
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
      {
        param_names__.emplace_back(std::string() + "theta" + '.' + std::to_string(sym1__));
      }}
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "times_to_be_best" + '.' + std::to_string(sym1__));
        }}
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    for (int sym1__ = 1; sym1__ <= K; ++sym1__) {
      {
        param_names__.emplace_back(std::string() + "theta" + '.' + std::to_string(sym1__));
      }}
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= (K - 1); ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "times_to_be_best" + '.' + std::to_string(sym1__));
        }}
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"theta\",\"type\":{\"name\":\"vector\",\"length\":" << K << "},\"block\":\"parameters\"},{\"name\":\"times_to_be_best\",\"type\":{\"name\":\"vector\",\"length\":" << K << "},\"block\":\"generated_quantities\"}]";
    return s__.str();
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"theta\",\"type\":{\"name\":\"vector\",\"length\":" << K << "},\"block\":\"parameters\"},{\"name\":\"times_to_be_best\",\"type\":{\"name\":\"vector\",\"length\":" << (K - 1) << "},\"block\":\"generated_quantities\"}]";
    return s__.str();
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      std::vector<double> vars_vec(vars.size());
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i) {
        vars.coeffRef(i) = vars_vec[i];
      }
    }
    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }
    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }
    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }
  
    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits_impl(context, params_i, params_r_vec, pstream);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i) {
        params_r.coeffRef(i) = params_r_vec[i];
      }
    }
    inline void transform_inits(const stan::io::var_context& context,
                                std::vector<int>& params_i,
                                std::vector<double>& vars,
                                std::ostream* pstream = nullptr) const final {
      transform_inits_impl(context, params_i, vars, pstream);
    }        
};
}
using stan_model = model_betabinom_namespace::model_betabinom;
#ifndef USING_R
// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
stan::math::profile_map& get_stan_profile_data() {
  return model_betabinom_namespace::profiles__;
}
#endif
#endif
