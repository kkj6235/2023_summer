package hello.core.singleton;

import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;

import static org.assertj.core.api.Assertions.assertThat;

class StatefulServiceTest {

    @Test
    void statefulServiceSingleton(){
        ApplicationContext ac = new AnnotationConfigApplicationContext(TestConfig.class);
        StatefulService statefulService1 = ac.getBean(StatefulService.class);
        StatefulService statefulService2 = ac.getBean(StatefulService.class);
        // Thread A : 10000원 주문
        statefulService1.order("userA", 10000);
        // Thread B : 20000원 주문
        statefulService2.order("userB",20000);
//        Thread A : 사용자 A가 주문 금액 조회
        int price = statefulService1.getPrice();
        System.out.println("price = " + price);
        assertThat(statefulService1.getPrice()).isEqualTo(20000);
    }
    static class TestConfig{
        @Bean
        public StatefulService statefulSerivice(){
            return new StatefulService();
        }
    }

}