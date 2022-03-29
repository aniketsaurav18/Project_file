import { Container } from "./components/styled/container.styled";
import Header from "./components/header";
import { ThemeProvider } from "styled-components";
import GlobalStyles from "./components/styled/global";
import content from "./content";
import Card from "./components/card";
import Footer from "./components/Footer";

const theme = {
  color: {
    header: "#ebfbff",
    body: "#fff",
    footer: "#003333",
  },
  mobile: "768px",
};

function App() {
  return (
    <ThemeProvider theme={theme}>
      <>
        <GlobalStyles />
        <Header />
        <Container>
          {content.map((item, index) => (
            <Card key={index} item={item} />
          ))}
        </Container>
        <Footer />
      </>
    </ThemeProvider>
  );
}

export default App;
