module Styles = {
  open Css;
  let genesisSection =
    style([
      backgroundImage(`url("/static/img/GenesisMiddleBackground.jpg")),
      backgroundSize(`cover),
    ]);
  let background =
    style([
      backgroundImage(
        `url("/static/img/backgrounds/SectionGenesisBackground.jpg"),
      ),
      backgroundSize(`cover),
      paddingTop(`rem(12.)),
      overflow(`hidden),
    ]);
  // leaderboard css
  let disclaimer =
    merge([
      Theme.Type.disclaimer,
      style([paddingBottom(`rem(5.)), paddingTop(`rem(3.))]),
    ]);
  let leaderboardBackground =
    style([
      backgroundImage(`url("/static/img/backgrounds/SectionBackground.jpg")),
      backgroundSize(`cover),
    ]);

  let leaderboardContainer =
    style([
      height(`rem(65.)),
      width(`percent(100.)),
      position(`relative),
      overflow(`hidden),
      display(`flex),
      flexWrap(`wrap),
      marginLeft(`auto),
      marginRight(`auto),
      justifyContent(`center),
      media(Theme.MediaQuery.tablet, [height(`rem(43.))]),
    ]);

  let leaderboardTextContainer =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),
      justifyContent(`center),
      paddingTop(`rem(4.)),
      paddingBottom(`rem(2.)),
      width(`percent(100.)),
      media(
        Theme.MediaQuery.notMobile,
        [
          width(`percent(50.)),
          alignItems(`flexStart),
          justifyContent(`flexStart),
        ],
      ),
      selector(
        "button",
        [
          marginTop(`rem(2.)),
          important(maxWidth(`percent(50.))),
          width(`percent(100.)),
        ],
      ),
    ]);
  let leaderboardLink =
    style([width(`percent(100.)), textDecoration(`none)]);
};

module HowItWorksGrid = {
  module Styles = {
    open Css;
    let container =
      style([
        display(`flex),
        width(`percent(100.)),
        flexDirection(`column),
        media(
          Theme.MediaQuery.desktop,
          [flexDirection(`row), justifyContent(`spaceBetween)],
        ),
      ]);
    let grid =
      style([
        display(`grid),
        gridTemplateColumns([`rem(21.)]),
        gridAutoRows(`rem(15.43)),
        gridRowGap(`rem(1.)),
        marginTop(`rem(2.)),
        marginBottom(`rem(4.)),
        media(
          Theme.MediaQuery.tablet,
          [
            gridTemplateColumns([`rem(21.), `rem(21.)]),
            gridColumnGap(`rem(1.)),
          ],
        ),
        media(Theme.MediaQuery.desktop, [marginTop(`zero)]),
      ]);
    let h2 = merge([Theme.Type.h2, style([color(white)])]);
    let h4 = merge([Theme.Type.h4, style([fontWeight(`normal)])]);
    let gridItem = style([backgroundColor(white), padding(`rem(1.5))]);
    let link = merge([Theme.Type.link, style([textDecoration(`none)])]);
  };

  module GridItem = {
    [@react.component]
    let make = (~label="", ~children=?) => {
      <div className=Styles.gridItem>
        <h4 className=Styles.h4> {React.string(label)} </h4>
        <Spacer height=1. />
        {switch (children) {
         | Some(children) => children
         | None => <> </>
         }}
      </div>;
    };
  };

  [@react.component]
  let make = () => {
    <div className=Styles.container>
      <h2 className=Styles.h2> {React.string("How It Works")} </h2>
      <div className=Styles.grid>
        <GridItem label="What Members Do: Pre-Mainnet">
          <p className=Theme.Type.paragraph>
            {React.string(
               "Get hands-on experience developing applications with zero knowledge proofs, plus an overview of different types of constructions.",
             )}
          </p>
        </GridItem>
        <GridItem label="What Members Do: Post-Mainnet">
          <p className=Theme.Type.paragraph>
            {React.string(
               {j|Participate as block producers by continuously staking or delegating their Mina tokens — plus everything they were doing pre-mainnet. |j},
             )}
          </p>
        </GridItem>
        <GridItem label="Who is Selected">
          <p className=Theme.Type.paragraph>
            {React.string(
               "Highly engaged node operators and community leaders, with new Genesis Members being announced on a rolling basis until we reach a thousand.",
             )}
          </p>
        </GridItem>
        <GridItem label="What They Get">
          <p className=Theme.Type.paragraph>
            {React.string(
               "To ensure decentralization, Mina has allocated 6.6% of the protocol (or 66,000 Mina tokens) to Genesis Founding Members.",
             )}
          </p>
          // TODO: Add link here to terms and conditions
          <Next.Link href="/tcGenesis">
            <a className=Styles.link>
              {React.string("Read Terms and Conditions.")}
            </a>
          </Next.Link>
        </GridItem>
      </div>
    </div>;
  };
};

module CultureFooter = {
  module Styles = {
    open Css;
    let grid =
      style([
        display(`flex),
        height(`rem(17.)),
        backgroundImage(
          `url("/static/img/backgrounds/MinaCultureFooterDesktop.png"),
        ),
        backgroundSize(`cover),
        flexDirection(`column),
        padding2(~v=`rem(3.), ~h=`rem(2.75)),
        justifyContent(`spaceBetween),
        media(
          Theme.MediaQuery.tablet,
          [
            gridTemplateColumns([`rem(6.56), `rem(30.8)]),
            gridColumnGap(`rem(3.31)),
            gridTemplateRows([`rem(4.875), `rem(1.)]),
            padding2(~v=`rem(1.8), ~h=`rem(2.68)),
            height(`rem(11.)),
          ],
        ),
        media(
          Theme.MediaQuery.desktop,
          [
            display(`grid),
            gridTemplateColumns([`rem(12.93), `rem(47.)]),
            gridColumnGap(`rem(2.56)),
            gridTemplateRows([`rem(4.), `rem(1.)]),
            padding2(~v=`rem(2.5), ~h=`rem(2.5)),
            height(`rem(11.)),
          ],
        ),
      ]);
    let culture =
      style([
        Theme.Typeface.monumentGrotesk,
        color(white),
        fontSize(`rem(2.)),
      ]);
    let body = merge([Theme.Type.paragraphSmall, style([color(white)])]);
    let link =
      style([
        media(
          Theme.MediaQuery.tablet,
          [unsafe("grid-area", "2 / 2 / 3 /3 "), height(`rem(1.))],
        ),
        marginTop(`zero),
      ]);

    let anchor =
      style([
        Theme.Typeface.monumentGrotesk,
        cursor(`pointer),
        color(Theme.Colors.orange),
        display(`flex),
        textDecoration(`none),
      ]);
  };
  [@react.component]
  let make = () => {
    <Wrapped>
      <div className=Styles.grid>
        <h2 className=Styles.culture> {React.string("Our Culture")} </h2>
        <p className=Styles.body>
          {React.string(
             "It's hard to quantify, but it's not hard to see: in any community, culture is everything.  Ours is rooted in respect and openness, curiosity and excellence.",
           )}
        </p>
        <div className=Styles.link>
          <a className=Styles.anchor href=Constants.minaCodeOfConduct>
            {React.string("Read our Code of Conduct")}
            <Icon kind=Icon.ArrowRightMedium />
          </a>
        </div>
      </div>
      <Spacer height=1. />
    </Wrapped>;
  };
};

[@react.component]
let make = (~profiles) => {
  <Page title="Genesis Page">
    <div className=Nav.Styles.spacer />
    <Hero
      title="Community"
      header={Some("Genesis Program")}
      copy={
        Some(
          "We're looking for community members to join the Genesis Token Grant Program and form the backbone of Mina's robust decentralized network.",
        )
      }
      background=Theme.{
        mobile: "/static/img/backgrounds/GenesisHeroMobile.jpg",
        tablet: "/static/img/backgrounds/GenesisHeroTablet.jpg",
        desktop: "/static/img/backgrounds/GenesisHeroDesktop.jpg",
      }>
      <Spacer height=2. />
      <Button
        href={`External(Constants.genesisGrantApplication)}
        bgColor=Theme.Colors.digitalBlack>
        {React.string("Apply Now")}
        <Icon kind=Icon.ArrowRightSmall />
      </Button>
    </Hero>
    <div className=Styles.background>
      <FeaturedSingleRow
        row={
          FeaturedSingleRow.Row.rowType: ImageLeftCopyRight,
          title: "Become a Genesis Member",
          copySize: `Small,
          description: "Up to 1,000 community participants will be selected to help us harden Mina's protocol, strengthen the network and receive a distribution of 66,000 tokens.",
          textColor: Theme.Colors.white,
          image: "/static/img/GenesisCopy.jpg",
          background: Image(""),
          contentBackground: Image("/static/img/BecomeAGenesisMember.jpg"),
          link:
            FeaturedSingleRow.Row.Button({
              FeaturedSingleRow.Row.buttonText: "Apply Now",
              buttonColor: Theme.Colors.orange,
              buttonTextColor: Theme.Colors.white,
              dark: true,
              href: `External(Constants.genesisGrantApplication),
            }),
        }>
        <Spacer height=4. />
        <Rule color=Theme.Colors.white />
        <Spacer height=4. />
        <HowItWorksGrid />
        <Rule color=Theme.Colors.white />
        <Carousel
          title="Genesis Founding Members"
          copy={
            "Get to know some of the Founding Members working to strengthen the protocol and build our community."
            ->Some
          }
          cardKind={Carousel.GenesisMembers(profiles)}
          dark=false
          numberOfItems={Array.length(profiles)}
        />
      </FeaturedSingleRow>
    </div>
    <div className=Styles.genesisSection>
      <Spacer height=2. />
      <Wrapped> <WorldMapSection /> </Wrapped>
      <Spacer height=7.25 />
      <div className=Styles.leaderboardBackground>
        <Wrapped>
          <div className=Styles.leaderboardTextContainer>
            <h2 className=Theme.Type.h2>
              {React.string("Testnet Leaderboard")}
            </h2>
            <Spacer height=1. />
            <p className=Theme.Type.paragraphMono>
              {React.string(
                 "Mina rewards community members for contributing to Testnet with Testnet Points, making them stronger applicants for the Genesis Program. ",
               )}
            </p>
            <Button
              bgColor=Theme.Colors.orange href={`Internal("/leaderboard")}>
              {React.string("See The Full Leaderboard")}
              <Icon kind=Icon.ArrowRightSmall />
            </Button>
          </div>
          <div className=Styles.leaderboardContainer>
            <a href="/leaderboard" className=Styles.leaderboardLink>
              <Leaderboard interactive=false />
            </a>
          </div>
          <p className=Styles.disclaimer>
            {React.string(
               "Testnet Points are designed solely to track contributions to the Testnet and are non-transferable. Testnet Points have no cash or monetary value and are not redeemable for any cryptocurrency or digital assets. We may amend or eliminate Testnet Points at any time.",
             )}
          </p>
        </Wrapped>
        <CultureFooter />
        <Spacer height=4. />
      </div>
    </div>
  </Page>;
};

Next.injectGetInitialProps(make, _ => {
  Contentful.getEntries(
    Lazy.force(Contentful.client),
    {
      "include": 1,
      "content_type": ContentType.GenesisProfile.id,
      "order": "-fields.publishDate",
    },
  )
  |> Promise.map((entries: ContentType.GenesisProfile.entries) => {
       let profiles =
         Array.map(
           (e: ContentType.GenesisProfile.entry) => e.fields,
           entries.items,
         );
       {"profiles": profiles};
     })
});
