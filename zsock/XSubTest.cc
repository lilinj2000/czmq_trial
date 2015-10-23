#include "gtest/gtest.h"

#include "czmq.h"

#include "soil/Log.hh"
#include "soil/Condition.hh"

namespace trial
{

class XSubTest : public ::testing::Test
{
 public:
  XSubTest():
      xsub_endpoint_("tcp://127.0.0.1:5560"),
      xpub_endpoint_("tcp://127.0.0.1:5561")
  {
    cond_.reset( soil::Condition::create() );
  }
  
  void SetUp()
  {
    
    proxy_ = zactor_new(zproxy, NULL);

    zstr_sendx (proxy_, "FRONTEND", "XSUB", xsub_endpoint_.data(), NULL);
    zsock_wait(proxy_);

    zstr_sendx (proxy_, "BACKEND", "XPUB", xpub_endpoint_.data(), NULL);
    zsock_wait(proxy_);

  }

  void TearDown()
  {
    zactor_destroy( &proxy_ );
  }

 protected:
  std::string xsub_endpoint_;
  std::string xpub_endpoint_;

  zactor_t* proxy_;

  std::auto_ptr<soil::Condition> cond_;
};

TEST_F(XSubTest, pubTest)
{
  std::string filter = "test ";
  
  zsock_t* pub = zsock_new_pub( (">" + xsub_endpoint_).data() );
  ASSERT_TRUE( pub!=NULL );

  zsock_t* sub = zsock_new_sub( xpub_endpoint_.data(), filter.data() );
  ASSERT_TRUE( sub!=NULL );

  cond_->wait(1000);

  std::string hello = filter + "Hello, World!";
  SOIL_DEBUG <<"send msg: " <<hello;
  
  zstr_send( pub, hello.data() );

  zmsg_t* zmsg = zmsg_recv( sub );
  ASSERT_TRUE( zmsg!=NULL );

  char* msg = zmsg_popstr(zmsg);
  SOIL_DEBUG <<"recv msg: " <<msg;

  free( msg );
  zmsg_destroy( &zmsg );
  
  zsock_destroy( &pub );
  zsock_destroy( &sub );

  ASSERT_TRUE( true );
}


};  
