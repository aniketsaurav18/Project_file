import { StyledHeader, Logo, Nav, Image } from "./styled/styledHeader";
import { Button } from "./styled/Button.styled";
import { Container } from "./styled/container.styled";
import { Flex } from "./styled/Flex.styled";

export default function Header() {
  return (
    <StyledHeader>
      <Container>
        <Nav>
          <Logo src=".././images/logo.svg" alt="" />
          <Button type="button">Try it for Free</Button>
        </Nav>
        <Flex>
          <div>
            <h1>Build The Community Your Fans Will Love</h1>
            <p>
              Huddle re-imagines the way we build communities. You have a voice,
              but so does your audience. Create connections with your users as
              you engage in genuine discussion.
            </p>
            <Button bg="#ff0099" color="#fff">
              Get Started for free
            </Button>
          </div>
          <Image src=".././images/illustration-mockups.svg" />
        </Flex>
      </Container>
    </StyledHeader>
  );
}
