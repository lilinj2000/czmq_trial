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
  std::string filter = "";
  
  zsock_t* pub1 = zsock_new_pub( (">" + xsub_endpoint_).data() );
  ASSERT_TRUE( pub1!=NULL );

  zsock_t* pub2 = zsock_new_pub( (">" + xsub_endpoint_).data() );
  ASSERT_TRUE( pub2!=NULL );

  zsock_t* sub = zsock_new_sub( xpub_endpoint_.data(), filter.data() );
  ASSERT_TRUE( sub!=NULL );

  cond_->wait(1000);

  std::string hello1 = filter + "Hello, World! pub1";
  SOIL_DEBUG <<"send msg: " <<hello1;
  
  zstr_send( pub1, hello1.data() );

  std::string hello2 = filter + "Hello, World! pub2";
  SOIL_DEBUG <<"send msg: " <<hello2;
  
  zstr_send( pub2, hello2.data() );

  for(int i=0; i<2; i++)
  {
    zmsg_t* zmsg = zmsg_recv( sub );
    ASSERT_TRUE( zmsg!=NULL );

    char* msg = zmsg_popstr(zmsg);
    SOIL_DEBUG <<"recv msg: " <<msg;

    free( msg );
    zmsg_destroy( &zmsg );
  }
  
  zsock_destroy( &pub1 );
  zsock_destroy( &pub2 );
  zsock_destroy( &sub );

  ASSERT_TRUE( true );
}


};  
