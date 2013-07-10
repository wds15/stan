#include <stan/math/matrix/sd.hpp>
#include <gtest/gtest.h>
#include <stan/math/matrix/typedefs.hpp>
#include <stan/agrad/fwd/matrix/typedefs.hpp>
#include <stan/agrad/fwd/sqrt.hpp>
#include <stan/agrad/fwd/operator_multiplication.hpp>
#include <stan/agrad/fwd/operator_addition.hpp>
#include <stan/agrad/fwd/operator_division.hpp>
#include <stan/agrad/fwd/operator_subtraction.hpp>
#include <stan/agrad/var.hpp>
#include <test/agrad/util.hpp>

TEST(AgradFwdMatrixSD, fd_vector) {
  using stan::math::sd;
  using stan::math::vector_d;
  using stan::agrad::vector_fd;

  vector_d v(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));

  vector_d d1(6);
  vector_fd v1(6);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
                   
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_);
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_);
  
  d1.resize(1);
  v1.resize(1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_);
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_);
}
TEST(AgradFwdMatrixSD, fd_vector_exception) {
  using stan::math::sd;
  using stan::math::vector_d;
  using stan::agrad::vector_fd;

  vector_d d1;
  vector_fd v1;
  EXPECT_THROW(sd(d1), std::domain_error);
  EXPECT_THROW(sd(v1), std::domain_error);
}
TEST(AgradFwdMatrixSD, fd_rowvector) {
  using stan::math::sd;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fd;

  row_vector_d v(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));


  row_vector_d d1(6);
  row_vector_fd v1(6);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
                   
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_);
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_);

  d1.resize(1);
  v1.resize(1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_);
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_);
}
TEST(AgradFwdMatrixSD, fd_rowvector_exception) {
  using stan::math::sd;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fd;

  row_vector_d d;
  row_vector_fd v;
  
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);
}
TEST(AgradFwdMatrixSD, fd_matrix) {
  using stan::math::sd;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fd;

  matrix_d v(1,1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));

  matrix_d d1(2, 3);
  matrix_fd v1(2, 3);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_);
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_);

  d1.resize(1, 1);
  v1.resize(1, 1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_);
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_);
}
TEST(AgradFwdMatrixSD, fd_matrix_exception) {
  using stan::math::sd;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fd;

  matrix_d d;
  matrix_fd v;

  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);

  d.resize(1, 0);
  v.resize(1, 0);
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);

  d.resize(0, 1);
  v.resize(0, 1);
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);
}
TEST(AgradFwdMatrixSD, fv_vector) {
  using stan::math::sd;
  using stan::math::vector_d;
  using stan::agrad::vector_fv;

  vector_d v(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));

  vector_d d1(6);
  vector_fv v1(6);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
                   
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_.val());
  
  d1.resize(1);
  v1.resize(1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_.val());
}
TEST(AgradFwdMatrixSD, fv_vector_exception) {
  using stan::math::sd;
  using stan::math::vector_d;
  using stan::agrad::vector_fv;

  vector_d d1;
  vector_fv v1;
  EXPECT_THROW(sd(d1), std::domain_error);
  EXPECT_THROW(sd(v1), std::domain_error);
}
TEST(AgradFwdMatrixSD, fv_rowvector) {
  using stan::math::sd;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fv;

  row_vector_d v(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));


  row_vector_d d1(6);
  row_vector_fv v1(6);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
                   
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_.val());

  d1.resize(1);
  v1.resize(1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_.val());
}
TEST(AgradFwdMatrixSD, fv_rowvector_exception) {
  using stan::math::sd;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fv;

  row_vector_d d;
  row_vector_fv v;
  
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);
}
TEST(AgradFwdMatrixSD, fv_matrix) {
  using stan::math::sd;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;

  matrix_d v(1,1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));

  matrix_d d1(2, 3);
  matrix_fv v1(2, 3);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_.val());

  d1.resize(1, 1);
  v1.resize(1, 1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_.val());
}
TEST(AgradFwdMatrixSD, fv_matrix_exception) {
  using stan::math::sd;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;

  matrix_d d;
  matrix_fv v;

  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);

  d.resize(1, 0);
  v.resize(1, 0);
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);

  d.resize(0, 1);
  v.resize(0, 1);
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);
}
TEST(AgradFwdMatrixSD, ffd_vector) {
  using stan::math::sd;
  using stan::math::vector_d;
  using stan::agrad::vector_ffd;

  vector_d v(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));

  vector_d d1(6);
  vector_ffd v1(6);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
                   
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_.val());
  
  d1.resize(1);
  v1.resize(1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_.val());
}
TEST(AgradFwdMatrixSD, ffd_vector_exception) {
  using stan::math::sd;
  using stan::math::vector_d;
  using stan::agrad::vector_ffd;

  vector_d d1;
  vector_ffd v1;
  EXPECT_THROW(sd(d1), std::domain_error);
  EXPECT_THROW(sd(v1), std::domain_error);
}
TEST(AgradFwdMatrixSD, ffd_rowvector) {
  using stan::math::sd;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_ffd;

  row_vector_d v(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));


  row_vector_d d1(6);
  row_vector_ffd v1(6);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
                   
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_.val());

  d1.resize(1);
  v1.resize(1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_.val());
}
TEST(AgradFwdMatrixSD, ffd_rowvector_exception) {
  using stan::math::sd;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_ffd;

  row_vector_d d;
  row_vector_ffd v;
  
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);
}
TEST(AgradFwdMatrixSD, ffd_matrix) {
  using stan::math::sd;
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffd;

  matrix_d v(1,1);
  v << 1.0;
  EXPECT_FLOAT_EQ(0.0, sd(v));

  matrix_d d1(2, 3);
  matrix_ffd v1(2, 3);
  
  d1 << 1, 2, 3, 4, 5, 6;
  v1 << 1, 2, 3, 4, 5, 6;
   v1(0).d_ = 1.0;
   v1(1).d_ = 2.0;
   v1(2).d_ = 2.0;
   v1(3).d_ = 2.0;
   v1(4).d_ = 2.0;
   v1(5).d_ = 2.0;
  
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(d1));
  EXPECT_FLOAT_EQ(std::sqrt(17.5/5.0), sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.26726124, sd(v1).d_.val());

  d1.resize(1, 1);
  v1.resize(1, 1);
  EXPECT_FLOAT_EQ(0.0, sd(d1));
  EXPECT_FLOAT_EQ(0.0, sd(v1).val_.val());
  EXPECT_FLOAT_EQ(0.0, sd(v1).d_.val());
}
TEST(AgradFwdMatrixSD, ffd_matrix_exception) {
  using stan::math::sd;
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffd;

  matrix_d d;
  matrix_ffd v;

  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);

  d.resize(1, 0);
  v.resize(1, 0);
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);

  d.resize(0, 1);
  v.resize(0, 1);
  EXPECT_THROW(sd(d), std::domain_error);
  EXPECT_THROW(sd(v), std::domain_error);
}
